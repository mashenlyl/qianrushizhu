#include "stdio.h"

void uart_init(void);
void pwm_init(void);

int main (void)
{
	uart_init();
	pwm_init();
	
	while(1)						//为了让它一直输出
	{
		putc('Y');
		delay();					//这是在led.c上的函数，可以在这里直接调用
	}
	
	return 0;
}


































