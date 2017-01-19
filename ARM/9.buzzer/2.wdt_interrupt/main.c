#include "stdio.h"
#include "int.h"
#include "main.h"

void uart_init(void);
void wdt_init_interrupt(void);
void feed_dog(void);

void delay(void)
{
	volatile int i, j;
	for(i=0; i<5000; i++)
		for(j=0; j<100; j++);
}

int main(void)
{
	uart_init();
	wdt_init_interrupt();
	
	// 如果程序中要使用中断，就要调用中断初始化来初步初始化中断控制器
	system_init_exception();
	
	printf("-------------key interrypt test--------------");
	
	// 绑定isr到中断控制器硬件
	intc_setvectaddr(NUM_WDT, isr_wdt);
	
	// 使能中断
	intc_enable(NUM_WDT);
	
	
	while(1)
	{
		delay();
		feed_dog();
	}
	
	
	
	while(1);
	
	return 0;
}