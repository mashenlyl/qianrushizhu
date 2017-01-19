#include "stdio.h"
#include "main.h"


int main(void)
{
	uart_init();
	
	
	printf("-------ADC test--------\n");
	adc_use();
	
	return 0;
}