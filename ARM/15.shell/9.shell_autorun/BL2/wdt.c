#include "stdio.h"
#include "int.h"

#define		WTCON 		(0xE2700000)  
#define 	WTDAT 		(0xE2700004) 
#define		WTCNT 		(0xE2700008) 
#define 	WTCLRINT	(0xE270000C)

#define		rWTCON		(*(volatile unsigned int *)WTCON)
#define		rWTDAT		(*(volatile unsigned int *)WTDAT)
#define		rWTCNT		(*(volatile unsigned int *)WTCNT)
#define		rWTCLRINT	(*(volatile unsigned int *)WTCLRINT)

extern int g_bootdelay;
extern int g_isgo;

void wdt_init_interrupt(void)
{
	//首先，我们就设置预分频器(8~15),先清零，然后再设置值为66，因为时钟源是PCLK（66MHz）得到1MHz
	rWTCON &= ~(0xff<<8);
	rWTCON |= (65<<8);
	
	//然后设置分频器（3~4），先清零，然后设置值为128，得到周期是128us
	rWTCON &= ~(0x3<<3);
	rWTCON |= (0x3<<3);
	
	//然后就选择中断模式了（2），关闭复位模式（0）
	rWTCON |= (1<<2);
	rWTCON &= ~(1<<0);
	
	//设置计数值了，就设置为1.28s
	rWTDAT = 7813;				
	rWTCNT = 7813;
	
	//最后，都设置好了，就开启看门狗定时器了（5）
	rWTCON |= (1<<5);
}

void isr_wdt(void)
{
	//这里主要有两步
	//一步就是设置你想要它执行的isr程序
	//在这里实现计时的功能，有两种情况：第一种，你看到计时的话，你可以按下去；第二种，你可以不按
	g_bootdelay--;
	
	//你按下这个键，我就让你看见它按回去了,
	putchar('\b');
	printf("%d", g_bootdelay);
	
	if(g_bootdelay == 0)
	{
		g_isgo = 1;
	}
	
	
	//第二步就是清零了
	//清除中断
	intc_clearvectaddr();
	rWTCLRINT = 1;					//这里是设置任意数就可以清零了
}


void wd_timer_init(void)
{
	wdt_init_interrupt();
	// 如果程序中要使用中断，就要调用中断初始化来初步初始化中断控制器
	system_init_exception();
	// 绑定isr到中断控制器硬件
	intc_setvectaddr(NUM_WDT, isr_wdt);
	// 使能中断
	intc_enable(NUM_WDT);
}























