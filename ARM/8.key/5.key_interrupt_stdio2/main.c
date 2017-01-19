#include "stdio.h"


void uart_init(void);

int main (void)
{
	uart_init();
	//key_init();
	//key_polling();
	
	//先初始化中断
	system_init_exception();
	//然后绑定isr的值
	intc_setvectaddr();
	//之后就是使能中断
	intc_enable();
	
	return 0;
}


































