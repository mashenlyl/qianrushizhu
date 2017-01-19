#include "main.h"

#define GPF0CON			(*(volatile unsigned long *)0xE0200120)
#define GPF1CON			(*(volatile unsigned long *)0xE0200140)
#define GPF2CON			(*(volatile unsigned long *)0xE0200160)
#define GPF3CON			(*(volatile unsigned long *)0xE0200180)

#define GPD0CON			(*(volatile unsigned long *)0xE02000A0)
#define GPD0DAT			(*(volatile unsigned long *)0xE02000A4)

#define CLK_SRC1		(*(volatile unsigned long *)0xe0100204)
#define CLK_DIV1		(*(volatile unsigned long *)0xe0100304)
#define DISPLAY_CONTROL	(*(volatile unsigned long *)0xe0107008)

#define VIDCON0			(*(volatile unsigned long *)0xF8000000)
#define VIDCON1			(*(volatile unsigned long *)0xF8000004)
#define VIDTCON2		(*(volatile unsigned long *)0xF8000018)
#define WINCON0 		(*(volatile unsigned long *)0xF8000020)
#define WINCON2 		(*(volatile unsigned long *)0xF8000028)
#define SHADOWCON 		(*(volatile unsigned long *)0xF8000034)
#define VIDOSD0A 		(*(volatile unsigned long *)0xF8000040)
#define VIDOSD0B 		(*(volatile unsigned long *)0xF8000044)
#define VIDOSD0C 		(*(volatile unsigned long *)0xF8000048)

#define VIDW00ADD0B0 	(*(volatile unsigned long *)0xF80000A0)
#define VIDW00ADD1B0 	(*(volatile unsigned long *)0xF80000D0)

#define VIDTCON0 		(*(volatile unsigned long *)0xF8000010)
#define VIDTCON1 		(*(volatile unsigned long *)0xF8000014)

#define HSPW 			(40)				// 1~40 DCLK
#define HBPD			(10 - 1)			// 46
#define HFPD 			(240 - 1)			// 16 210 354
#define VSPW			(20)				// 1~20 DCLK
#define VBPD 			(10 - 1)			// 23
#define VFPD 			(30 - 1)			// 7 22 147



// FB地址
#define FB_ADDR			(0x23000000)
#define ROW				(600)
#define COL				(1024)
#define HOZVAL			(COL-1)
#define LINEVAL			(ROW-1)

#define XSIZE			COL
#define YSIZE			ROW


// 初始化LCD
void lcd_init(void)
{
	// 看原理图中LCD的引脚和SOC的GPIO（GPF0,1,2,3）相连接，所以我们就取配置GPIO
	// 看数据手册我们看以看到，选择LCD的功能是设置为2就可以了，也就是LCD_VD那个选项
	// 配置引脚用于LCD功能
	GPF0CON = 0x22222222;
	GPF1CON = 0x22222222;
	GPF2CON = 0x22222222;
	GPF3CON = 0x22222222;

	// 看原理图那里可以看到LED-背光那里是和PWMTOUT0连接的，我们直接设置为输出模式，输出0，让他亮就可以了
	// 我们也可以设置更复杂一些的pwm，然后就可以调节背光的亮度了
	// 打开背光	GPD0_0（PWMTOUT0）
	GPD0CON &= ~(0xf<<0);
	GPD0CON |= (1<<0);			// output mode
	GPD0DAT &= ~(1<<0);			// output 0 to enable backlight

	// 设置为10的话，三个接口都是FIMD模式了
	// 10: RGB=FIMD I80=FIMD ITU=FIMD
	DISPLAY_CONTROL = 2<<0;

	// bit[26~28]:使用RGB接口
	// bit[18]:RGB 并行
	// bit[2]:选择时钟源为HCLK_DSYS=166MHz
	VIDCON0 &= ~( (3<<26)|(1<<18)|(1<<2) );

	// bit[1]:使能lcd控制器
	// bit[0]:当前帧结束后使能lcd控制器
	VIDCON0 |= ( (1<<0)|(1<<1) );

	// bit[6]:选择需要分频
	// bit[6~13]:分频系数为5，即VCLK = 166M/(4+1) = 33M
	VIDCON0 |= 4<<6 | 1<<4;


	// 这里设置1就是Inverted的意思，反转，0就是正常
	// H43-HSD043I9W1.pdf(p13) 时序图：VSYNC和HSYNC都是低脉冲
	// s5pv210芯片手册(p1207) 时序图：VSYNC和HSYNC都是高脉冲有效，所以需要反转
	VIDCON1 |= 1<<5 | 1<<6;

	//它这里时序这些VBPD这些是扫描一行像素或者一帧图片的时间的，这些是和那个分辨率是没有什么关系的，所以
	//分辨率虽然改变了，但是我们不用改变这些参数
	// 设置时序
	VIDTCON0 = VBPD<<16 | VFPD<<8 | VSPW<<0;
	VIDTCON1 = HBPD<<16 | HFPD<<8 | HSPW<<0;
	//这里设置长宽就需要改变了，不过这里的长宽已经在上面改变了，这里也不需要改动了
	// 设置长宽(物理屏幕)
	VIDTCON2 = (LINEVAL << 11) | (HOZVAL << 0);

	// 设置window0
	// bit[0]:使能
	// bit[2~5]:24bpp（RGB888）
	WINCON0 |= 1<<0;
	WINCON0 &= ~(0xf << 2);
	WINCON0 |= (0xB<<2) | (1<<15);

#define LeftTopX     0
#define LeftTopY     0
#define RightBotX   1023
#define RightBotY   599

	// 设置window0的上下左右
	// 设置的是显存空间的大小
	VIDOSD0A = (LeftTopX<<11) | (LeftTopY << 0);
	VIDOSD0B = (RightBotX<<11) | (RightBotY << 0);
	VIDOSD0C = (LINEVAL + 1) * (HOZVAL + 1);


	//和最后那个数字未与的话，也就是说他最大不可以超过0xffffff（24位的最大值）位与后如果不超过还是它自己本身
	// 设置fb的地址
	VIDW00ADD0B0 = FB_ADDR;
	VIDW00ADD1B0 = (((HOZVAL + 1)*4 + 0) * (LINEVAL + 1)) & (0xffffff);

	// 使能channel 0传输数据
	SHADOWCON = 0x1;
}





