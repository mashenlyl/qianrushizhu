#include "stdio.h"

void uart_init(void);

int main (void)
{
	uart_init();
	
	int a = 1234;
	printf("Test for printf,a = %d.\n", a);
	printf("This is printf.\n");
	/*
	while(1)						//为了让它一直输出
	{
		uart_putc('Y');
		uart_getc();
		uart_putc('N');
		delay();					//这是在led.c上的函数，可以在这里直接调用
	}
	*/
	return 0;
}

































