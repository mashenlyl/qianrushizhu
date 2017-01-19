#include "main.h"

#define ADC_REGISTER_BASE	0xE1700000

#define rTSADCCON0			(*(volatile unsigned int *)(ADC_REGISTER_BASE + 0x0))
#define rTSDATX0			(*(volatile unsigned int *)(ADC_REGISTER_BASE + 0xC))
#define rTSDATY0			(*(volatile unsigned int *)(ADC_REGISTER_BASE + 0x10))
#define rCLRINTADC0			(*(volatile unsigned int *)(ADC_REGISTER_BASE + 0x18))
#define rADCMUX				(*(volatile unsigned int *)(ADC_REGISTER_BASE + 0x1C))

void adc_init(void)
{
	//选择12位精度的ADC输出
	rTSADCCON0 |= (1<<16);
	//14位选择分频
	rTSADCCON0 |= (1<<14);
	//13~6位选择分多少的，我们选择66/(65+1)=1MHz,先清零，后写值
	//由于我在这里清零错误，导致下面出错了
	rTSADCCON0 &= ~(0xFF<<6);
	rTSADCCON0 |= (65<<6);
	//第2位选择正常模式的
	rTSADCCON0 &= ~(1<<2);
	//第1位也是选择正常模式
	rTSADCCON0 &= ~(1<<1);
	
	//最后选择是哪个通道的，我们是通道0
	rADCMUX &= ~(1<<0);
	
}

//static说明它是内部使用的函数
static void delay(void)
{
	volatile int i, j;
	for(i=0; i<4000; i++)
		for(j=0; j<1000; j++);
}

void adc_use(void)
{
	//首先，初始化adc
	adc_init();
	
	unsigned int val = 0;
	
	while(1)
	{
		//第一步：打开ADC
		rTSADCCON0 |= (1<<0);
		//第二步：等待ADC转换完毕,判断第15位是否是1，是1就表明转换完毕了
		while(!(rTSADCCON0 & (1<<15)));
		
		//第三步：读取ADC中的数据，并处理数据
		//读取数据是在TSDATX0寄存器和TSDATY0寄存器上的；
		val = rTSDATX0;
		printf("The rTSDATX0 bit14 = %d.\n", (val & (1<<14)));
		printf("ADC rTSDATX0 data = %d.\n", (val & (0xFFF<<0)));
		
		val = rTSDATY0;
		printf("The rTSDATY0 bit14 = %d.\n", (val & (1<<14)));
		printf("ADC rTSDATY0 data = %d.\n", (val & (0xFFF<<0)));
		
		//第四步：延时一下
		delay();
	}
	
	
}






















