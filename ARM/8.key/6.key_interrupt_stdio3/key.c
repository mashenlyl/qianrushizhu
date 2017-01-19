#include "stdio.h"
#include "main.h"
#include "inter.h"

//EXT_CON、EXT_PEND、EXT_MASK寄存器
#define EXT_INT_0_CON  0xE0200E00
#define EXT_INT_2_CON  0xE0200E08
#define EXT_INT_0_PEND 0xE0200F40
#define EXT_INT_2_PEND 0xE0200F48
#define EXT_INT_0_MASK 0xE0200F00
#define EXT_INT_2_MASK 0xE0200F08

//访问EXT_CON、EXT_PEND、EXT_MASK寄存器
#define rEXT_INT_0_CON		(*(volatile unsigned int *)EXT_INT_0_CON)
#define rEXT_INT_2_CON		(*(volatile unsigned int *)EXT_INT_2_CON)
#define rEXT_INT_0_PEND		(*(volatile unsigned int *)EXT_INT_0_PEND)
#define rEXT_INT_2_PEND		(*(volatile unsigned int *)EXT_INT_2_PEND)
#define rEXT_INT_0_MASK		(*(volatile unsigned int *)EXT_INT_0_MASK)
#define rEXT_INT_2_MASK		(*(volatile unsigned int *)EXT_INT_2_MASK)


//GPH0寄存器
#define GPH0CON		0xE0200C00
#define GPH0DAT		0xE0200C04
#define GPH2CON		0xE0200C40
#define GPH2DAT		0xE0200C44

//访问GPH0寄存器
#define rGPH0CON		(*(volatile unsigned int *)GPH0CON)
#define rGPH0DAT		(*(volatile unsigned int *)GPH0DAT)
#define rGPH2CON		(*(volatile unsigned int *)GPH2CON)
#define rGPH2DAT		(*(volatile unsigned int *)GPH2DAT)


//--------------------轮询方式-------------------
void key_init(void)
{
	//置为0的时候IO口就是input模式
	// bit 8~15位置为0
	rGPH0CON &= (~(0xff<<8));
	// bit 0~15位置为0
	rGPH2CON &= (~(0xffff<<0));
}

void key_polling(void)
{
	while(1)
	{
		if(rGPH0DAT & (1<<2))
		{
			led_off();
			//这里是1，就是按键弹开的时候，全部led都熄灭
		}
		else
		{
			led1();
			//这里是0，就是按键按下的时候,然后就亮一个led
			printf("This is left key.\n");
		}

	

		if(rGPH0DAT & (1<<3))
		{
			led_off();
			//这里是1，就是按键弹开的时候，全部led都熄灭
		}
		else
		{
			led2();
			//这里是0，就是按键按下的时候,然后就亮一个led
			printf("This is another key.\n");
		}
	}
}

//-------------------------中断方式--------------

// 第一步：外部中断对应的GPIO模式设置
// 对应的接口是：EINT2、EINT3、EINT16、EINT17、EINT18、EINT19
void key_inter_init(void)
{
	//GPH0设置是外部中断模式
	rGPH0CON |= (0xff<<8);
	rGPH2CON |= (0xffff<<0);
	
	//设置EXT_CON寄存器，就是设置是什么触发状态，有电平触发，边缘触发，我们一般设置降低边缘触发
	//rEXT_INT_0_CON &= ~(0xFF<<8);
	rEXT_INT_0_CON |= ((2<<8)|(2<<12));
	//rEXT_INT_2_CON &= ~(0xFFFF<<0);
	rEXT_INT_2_CON |= ((2<<0)|(2<<4)|(2<<8)|(2<<12));
	
	//EXT_PEND寄存器,要先把它清零，而需要写1来进行清零
	rEXT_INT_0_PEND |= (3<<2);
	rEXT_INT_2_PEND |= (0xf<<0);
	
	//EXT_MASK寄存器，使能中断的，0就是使能
	rEXT_INT_0_MASK &= ~(3<<2);
	rEXT_INT_2_MASK &= ~(0xf<<0);
}

void isr_eint2(void)
{
	printf("key_eint2_left.\n");
	
	//之后要清零
	rEXT_INT_0_PEND |= (1<<2);
	//里面的中断体系也要清零
	intc_clearvectaddr();
}

void isr_eint3(void)
{
	printf("key_eint3_down.\n");
	
	//之后要清零
	rEXT_INT_0_PEND |= (1<<3);
	//里面的中断体系也要清零
	intc_clearvectaddr();
}

void isr_eint16171819(void)
{
	
	if(rEXT_INT_2_PEND &= 1<<0)
	{
		printf("key_eint16");
		rEXT_INT_2_PEND |= (1<<0);
	}
	else if(rEXT_INT_2_PEND &= 1<<1)
	{
		printf("key_eint17");
		rEXT_INT_2_PEND |= (1<<1);
	}
	else if(rEXT_INT_2_PEND &= 1<<2)
	{
		printf("key_eint18");
		rEXT_INT_2_PEND |= (1<<2);
	}
	else if(rEXT_INT_2_PEND &= 1<<3)
	{
		printf("key_eint19");
		rEXT_INT_2_PEND |= (1<<3);
	}
	
	
	//里面的中断体系也要清零
	intc_clearvectaddr();
}



















