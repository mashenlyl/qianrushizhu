#include "stdio.h"

void uart_init(void);

int main(void)
{
	uart_init();
	
	int a = 1234;
	
	printf("test for printf, a = %d.\n", a);
	/*
	while(1)
	{
		uart_putc('a');
		delay();
	}
	*/
	return 0;
}