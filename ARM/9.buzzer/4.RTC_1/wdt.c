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


void wdt_init_interrupt(void)
{
	//首先，我们就设置预分频器(8~15),先清零，然后再设置值为66，得到1MHz
	rWTCON &= ~(0xff<<8);
	rWTCON |= (65<<8);
	
	//然后设置分频器（3~4），先清零，然后设置值为128，得到周期是128us
	rWTCON &= ~(0x3<<3);
	rWTCON |= (0x3<<3);
	
	//因为默认是复位的，所以不用选择了
	
	//设置计数值了，就设置为1.28s
	rWTDAT = 10000;				
	rWTCNT = 10000;
	
	//最后，都设置好了，就开启看门狗定时器了（5）
	rWTCON |= (1<<5);
}

























