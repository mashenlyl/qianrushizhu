#include "inter.h"
#include "stdio.h"


void reset_exception(void)
{
	printf("exception_reset.\n");
}

void undef_exception(void)
{
	printf("exception_undef.\n");
}

void sotf_int_exception(void)
{
	printf("exception_sotf_int.\n");
}

void prefetch_exception(void)
{
	printf("exception_prefetch.\n");
}

void data_exception(void)
{
	printf("exception_data.\n");
}

void irq_handler(void)
{
	printf("irq_handler.\n");
}

void fiq_exception(void)
{
	printf("exception_fiq.\n");
}

//这个是绑定常向量表,让CPU可以从异常向量表进入中断去处理中断程序
void system_init_exception(void)
{
	r_exception_reset 		= (unsigned int)reset_exception;
	r_exception_undef 		= (unsigned int)undef_exception;
	r_exception_sotf_int 	= (unsigned int)sotf_int_exception;
	r_exception_prefetch 	= (unsigned int)prefetch_exception;
	r_exception_data 		= (unsigned int)data_exception;
	r_exception_irq 		= (unsigned int)IRQ_handle;
	r_exception_fiq 		= (unsigned int)IRQ_handle;
	
	//初始化中断
	intc_init();
}


void intc_clearvectaddr(void)
{
	VIC0ADDR = 0x00;
	VIC1ADDR = 0x00;
	VIC2ADDR = 0x00;
	VIC3ADDR = 0x00;
}

// 初始化中断源，就是把所有的中断口都禁止掉，然后把VICnADDR清掉
void intc_init(void)
{
	//禁止所有的中断
	//为什么要禁止所有中断呢：防止一不小心触发其他的中断，引起错误
	VIC0INTENCLEAR = 0xffffffff;
	VIC1INTENCLEAR = 0xffffffff;
	VIC2INTENCLEAR = 0xffffffff;
	VIC3INTENCLEAR = 0xffffffff;
	
	//选择模式位irq
	VIC0INTSELECT = 0x00;
	VIC1INTSELECT = 0x00;
	VIC2INTSELECT = 0x00;
	VIC3INTSELECT = 0x00;
	
	//清除VICnADDR寄存器
	intc_clearvectaddr();
}

//把isr程序和VIC0VECTADDR寄存器绑定在一起
void intc_setvectaddr(unsigned long intnum, void (*handler)(void))
{
	if(intnum<32)
	{
		(*(volatile unsigned long *))(VIC0VECTADDR + 4*(intnum-0)) = (unsigned)handler;
	}
	else if(intnum<64)
	{
		(*(volatile unsigned long *))(VIC1VECTADDR + 4*(intnum-32)) = (unsigned)handler;
	}
	else if(intnum<96)
	{
		(*(volatile unsigned long *))(VIC2VECTADDR + 4*(intnum-64)) = (unsigned)handler;
	}
	else
	{
		(*(volatile unsigned long *))(VIC3VECTADDR + 4*(intnum-96)) = (unsigned)handler;
	}
}

//使能某些中断
void intc_enable(unsigned long intnum)
{
	unsigned long temp;
	if(intum<32)
	{
		temp = VIC0INTENABLE;
		temp |= (1<<intnum);
		VIC0INTENABLE = temp;
	}
	else if(intum<64)
	{
		temp = VIC1INTENABLE;
		temp |= (1<<(intnum-32));
		VIC1INTENABLE = temp;
	}
	else if(intum<96)
	{
		temp = VIC2INTENABLE;
		temp |= (1<<(intnum-64));
		VIC2INTENABLE = temp;
	}
	else if(intum<NUM_ALL)
	{
		temp = VIC3INTENABLE;
		temp |= (1<<(intnum-96));
		VIC3INTENABLE = temp;
	}
	else
	{
		VIC0INTENABLE = 0xffffffff;
		VIC1INTENABLE = 0xffffffff;
		VIC2INTENABLE = 0xffffffff;
		VIC3INTENABLE = 0xffffffff;
	}
}

//禁止某些中断
void intc_disable(unsigned long intnum)
{
	if(intum<32)
	{
		temp = VIC0INTENCLEAR;
		temp |= (1<<(intnum));
		VIC0INTENCLEAR = temp;
	}
	else if(intum<64)
	{
		temp = VIC1INTENCLEAR;
		temp |= (1<<(intnum-32));
		VIC1INTENCLEAR = temp;
	}
	else if(intum<96)
	{
		temp = VIC2INTENCLEAR;
		temp |= (1<<(intnum-64));
		VIC2INTENCLEAR = temp;
	}
	else if(intum<NUM_ALL)
	{
		temp = VIC3INTENCLEAR;
		temp |= (1<<(intnum-96));
		VIC3INTENCLEAR = temp;
	}
	else
	{
		VIC0INTENCLEAR = 0xffffffff;
		VIC1INTENCLEAR = 0xffffffff;
		VIC2INTENCLEAR = 0xffffffff;
		VIC3INTENCLEAR = 0xffffffff;
	}
}



//返回VIC0IRQSTATUS的值
unsigned long intc_getvicirqstatus(unsigned long ucontroller)
{
	if(ucontroller == 0)
		return VIC0IRQSTATUS;
	else if(ucontroller == 1)
		return VIC1IRQSTATUS;
	else if(ucontroller == 2)
		return VIC2IRQSTATUS;
	else if(ucontroller == 3)
		return VIC3IRQSTATUS;
}

//判断是哪一个中断源的
void irq_handler(void)
{
	unsigned long vicaddr[4] = {VIC0ADDR, VIC1ADDR, VIC2ADDR, VIC3ADDR};
	int i;
	(void)(*isr)(void) = NULL;
	
	for(i=0; i<4; i++)
	{
		//判断VIC0IRQSTATUS的值，如果某个值是1，那么就是对应的VICnADDR寄存器
		if(intc_getvicirqstatus(i) != 0)
		{
			isr = ((void)(*)(void)) vicaddr[i];
			break;
		}
	}
	//最后执行真正的isr程序
	isr();
}




























