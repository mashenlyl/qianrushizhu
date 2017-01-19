#include "main.h"
#include "ascii.h"

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


// FB��ַ
#define FB_ADDR			(0x23000000)
#define ROW				(600)
#define COL				(1024)
#define HOZVAL			(COL-1)
#define LINEVAL			(ROW-1)

#define XSIZE			COL
#define YSIZE			ROW

#define WIDTH			8

#define RED 	0xFF0000
#define GREEN 	0x00FF00
#define BLUE 	0x0000FF
#define WHITE 	0xFFFFFF


u32 *pfb = (u32 *)FB_ADDR;


// ��ʼ��LCD
void lcd_init(void)
{
	// ��ԭ��ͼ��LCD�����ź�SOC��GPIO��GPF0,1,2,3�������ӣ��������Ǿ�ȡ����GPIO
	// �������ֲ����ǿ��Կ�����ѡ��LCD�Ĺ���������Ϊ2�Ϳ����ˣ�Ҳ����LCD_VD�Ǹ�ѡ��
	// ������������LCD����
	GPF0CON = 0x22222222;
	GPF1CON = 0x22222222;
	GPF2CON = 0x22222222;
	GPF3CON = 0x22222222;

	// ��ԭ��ͼ������Կ���LED-���������Ǻ�PWMTOUT0���ӵģ�����ֱ������Ϊ���ģʽ�����0���������Ϳ�����
	// ����Ҳ�������ø�����һЩ��pwm��Ȼ��Ϳ��Ե��ڱ����������
	// �򿪱���	GPD0_0��PWMTOUT0��
	GPD0CON &= ~(0xf<<0);
	GPD0CON |= (1<<0);			// output mode
	GPD0DAT &= ~(1<<0);			// output 0 to enable backlight

	// ����Ϊ10�Ļ��������ӿڶ���FIMDģʽ��
	// 10: RGB=FIMD I80=FIMD ITU=FIMD
	DISPLAY_CONTROL = 2<<0;

	// bit[26~28]:ʹ��RGB�ӿ�
	// bit[18]:RGB ����
	// bit[2]:ѡ��ʱ��ԴΪHCLK_DSYS=166MHz
	VIDCON0 &= ~( (3<<26)|(1<<18)|(1<<2) );

	// bit[1]:ʹ��lcd������
	// bit[0]:��ǰ֡������ʹ��lcd������
	VIDCON0 |= ( (1<<0)|(1<<1) );

	// bit[6]:ѡ����Ҫ��Ƶ
	// bit[6~13]:��Ƶϵ��Ϊ5����VCLK = 166M/(4+1) = 33M
	VIDCON0 |= 4<<6 | 1<<4;


	// ��������1����Inverted����˼����ת��0��������
	// H43-HSD043I9W1.pdf(p13) ʱ��ͼ��VSYNC��HSYNC���ǵ�����
	// s5pv210оƬ�ֲ�(p1207) ʱ��ͼ��VSYNC��HSYNC���Ǹ�������Ч��������Ҫ��ת
	VIDCON1 |= 1<<5 | 1<<6;

	//������ʱ����ЩVBPD��Щ��ɨ��һ�����ػ���һ֡ͼƬ��ʱ��ģ���Щ�Ǻ��Ǹ��ֱ�����û��ʲô��ϵ�ģ�����
	//�ֱ�����Ȼ�ı��ˣ��������ǲ��øı���Щ����
	// ����ʱ��
	VIDTCON0 = VBPD<<16 | VFPD<<8 | VSPW<<0;
	VIDTCON1 = HBPD<<16 | HFPD<<8 | HSPW<<0;
	//�������ó������Ҫ�ı��ˣ���������ĳ����Ѿ�������ı��ˣ�����Ҳ����Ҫ�Ķ���
	// ���ó���(������Ļ)
	VIDTCON2 = (LINEVAL << 11) | (HOZVAL << 0);

	// ����window0
	// bit[0]:ʹ��
	// bit[2~5]:24bpp��RGB888��
	WINCON0 |= 1<<0;
	WINCON0 &= ~(0xf << 2);
	WINCON0 |= (0xB<<2) | (1<<15);

#define LeftTopX     0
#define LeftTopY     0
#define RightBotX   1023
#define RightBotY   599

	// ����window0����������
	// ���õ����Դ�ռ�Ĵ�С
	VIDOSD0A = (LeftTopX<<11) | (LeftTopY << 0);
	VIDOSD0B = (RightBotX<<11) | (RightBotY << 0);
	VIDOSD0C = (LINEVAL + 1) * (HOZVAL + 1);


	//������Ǹ�����δ��Ļ���Ҳ����˵����󲻿��Գ���0xffffff��24λ�����ֵ��λ�������������������Լ�����
	// ����fb�ĵ�ַ
	VIDW00ADD0B0 = FB_ADDR;
	VIDW00ADD1B0 = (((HOZVAL + 1)*4 + 0) * (LINEVAL + 1)) & (0xffffff);

	// ʹ��channel 0��������
	SHADOWCON = 0x1;
}

//���һ�����ص�ĺ���
static inline void lcd_display_pixel(u32 x, u32 y, u32 color)
{
	*(pfb + COL*y + x) = color;
}

//дһ������ɫ�ĺ���
static void lcd_set_blackground(u32 color)
{
	u32 x, y;
	for(y=0; y<=ROW; y++)
	{
		for(x=0; x<=COL; x++)
		{
			lcd_display_pixel(x,y,color);
		}
	}
}

//�ӳٺ���
static void lcd_delay(void)
{
	volatile u32 i, j;
	//ע�⣺�����Ǹ�forѭ��Ҫ����һ��;�ֺţ���Ȼ�ͳ�����
	for(i=0; i<4000; i++)
		for(j=0; j<1000; j++);
}


//��һ�����ߵĻ�������Ҫ�������꣨x1,y��(x2,y)
static void lcd_draw_hline(u32 x1, u32 x2, u32 y, u32 color)
{
	u32 x;
	
	for(x=x1; x<=x2; x++)
	{
		lcd_display_pixel(x,y,color);
	}
		
}


//��һ�����ߵĻ�������Ҫ�������꣨x,y1��(x,y2)
static void lcd_draw_vline(u32 x, u32 y1, u32 y2, u32 color)
{
	u32 y;
	
	for(y=y1; y<=y2; y++)
	{
		lcd_display_pixel(x,y,color);
	}
		
}


//��б�ߣ����Ǿ���Ҫֱ���������꣨x1,y1��(x2,y2)
void glib_line(u32 x1, u32 y1, u32 x2, u32 y2, u32 color)
{
	int dx,dy,e;
	dx=x2-x1; 
	dy=y2-y1;
    
	if(dx>=0)
	{
		if(dy >= 0) // dy>=0
		{
			if(dx>=dy) // 1/8 octant
			{
				e=dy-dx/2;  
				while(x1<=x2)
				{
					lcd_display_pixel(x1,y1,color);
					if(e>0){y1+=1;e-=dx;}	
					x1+=1;
					e+=dy;
				}
			}
			else		// 2/8 octant
			{
				e=dx-dy/2;
				while(y1<=y2)
				{
					lcd_display_pixel(x1,y1,color);
					if(e>0){x1+=1;e-=dy;}	
					y1+=1;
					e+=dx;
				}
			}
		}
		else		   // dy<0
		{
			dy=-dy;   // dy=abs(dy)

			if(dx>=dy) // 8/8 octant
			{
				e=dy-dx/2;
				while(x1<=x2)
				{
					lcd_display_pixel(x1,y1,color);
					if(e>0){y1-=1;e-=dx;}	
					x1+=1;
					e+=dy;
				}
			}
			else	 // 7/8 octant
			{
				e=dx-dy/2;
				while(y1>=y2)
				{
					lcd_display_pixel(x1,y1,color);
					if(e>0){x1+=1;e-=dy;}	
					y1-=1;
					e+=dx;
				}
			}
		}	
	}
	else //dx<0
	{
		dx=-dx;		//dx=abs(dx)
		if(dy >= 0) // dy>=0
		{
			if(dx>=dy) // 4/8 octant
			{
				e=dy-dx/2;
				while(x1>=x2)
				{
					lcd_display_pixel(x1,y1,color);
					if(e>0){y1+=1;e-=dx;}	
					x1-=1;
					e+=dy;
				}
			}
			else		// 3/8 octant
			{
				e=dx-dy/2;
				while(y1<=y2)
				{
					lcd_display_pixel(x1,y1,color);
					if(e>0){x1-=1;e-=dy;}	
					y1+=1;
					e+=dx;
				}
			}
		}
		else		   // dy<0
		{
			dy=-dy;   // dy=abs(dy)

			if(dx>=dy) // 5/8 octant
			{
				e=dy-dx/2;
				while(x1>=x2)
				{
					lcd_display_pixel(x1,y1,color);
					if(e>0){y1-=1;e-=dx;}	
					x1-=1;
					e+=dy;
				}
			}
			else		// 6/8 octant
			{
				e=dx-dy/2;
				while(y1>=y2)
				{
					lcd_display_pixel(x1,y1,color);
					if(e>0){x1-=1;e-=dy;}	
					y1-=1;
					e+=dx;
				}
			}
		}	
	}
}


//��Բ�����Ǿ���ҪԲ�ģ�x,y�����а뾶radius
void draw_circular(u32 centerX, u32 centerY, u32 radius, u32 color)
{
	u32 x,y ;
	u32 tempX,tempY;
    u32 SquareOfR = radius*radius;

	for(y=0; y<YSIZE; y++)
	{
		for(x=0; x<XSIZE; x++)
		{
			if(y<=centerY && x<=centerX)
			{
				tempY=centerY-y;
				tempX=centerX-x;                        
			}
			else if(y<=centerY&& x>=centerX)
			{
				tempY=centerY-y;
				tempX=x-centerX;                        
			}
			else if(y>=centerY&& x<=centerX)
			{
				tempY=y-centerY;
				tempX=centerX-x;                        
			}
			else if(y>=centerY&& x>=centerX)
			{
				tempY = y-centerY;
				tempX = x-centerX;
			}
			if ((tempY*tempY+tempX*tempX)<=SquareOfR)
				lcd_display_pixel(x, y, color);
		}
	}
}


//дһ���ַ���
static void show_8_16(unsigned int x, unsigned int y, unsigned int color, unsigned char *data)  
{  
// count��¼��ǰ���ڻ��Ƶ����صĴ���
    int i, j, count = 0;  
	
	//�����������ģ��8x16�ģ�Ҳ���ǿ���8������16��
    for (j=y; j<(y+16); j++)  
    {  
        for (i=x; i<(x+8); i++)  
        {  
            if (i<XSIZE && j<YSIZE)  
            {  
			// ������(i, j)������ش��ж���0����1�������1дcolor�������0ֱ������
            	if (data[count/8] & (1<<(count%8)))   
					lcd_display_pixel(i, j, color);
            }  
            count++;  
        }  
    }  
} 


//д�ַ�����
void draw_ascii_ok(unsigned int x, unsigned int y, unsigned int color, unsigned char *str)
{
	int i;  
	unsigned char *ch;
    for (i=0; str[i]!='\0'; i++)  
    {  
		ch = (unsigned char *)ascii_8_16[(unsigned char)str[i]-0x20];
        show_8_16(x, y, color, ch); 
		
        x += 8;
		if (x >= XSIZE)
		{
			x -= XSIZE;			// �س�
			y += 16;			// ����
		}
    }  
}


void lcd_test(void)
{
	lcd_init();
	
	lcd_set_blackground(WHITE);
	draw_ascii_ok(0,0,RED,"QR");

	
/*
	lcd_set_blackground(WHITE);
	glib_line(0,599,1023,0,BLUE);
	draw_circular(511,299,250,BLUE);
*/
	
/*
	lcd_set_blackground(WHITE);
	lcd_draw_hline(212,812,300,BLUE);
	lcd_draw_vline(512,100,500,BLUE);
*/
	
/*
	//��䱳��ɫ��
	while(1)
	{
		lcd_set_blackground(RED);
		lcd_delay();
		
		lcd_set_blackground(GREEN);
		lcd_delay();
		
		lcd_set_blackground(BLUE);
		lcd_delay();
	}
*/

}































