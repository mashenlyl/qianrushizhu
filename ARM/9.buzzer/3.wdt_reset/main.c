#include "stdio.h"
#include "int.h"
#include "main.h"

void uart_init(void);
void wdt_init_interrupt(void);

int main(void)
{
	uart_init();
	wdt_init_interrupt();
	
	// 如果程序中要使用中断，就要调用中断初始化来初步初始化中断控制器
	system_init_exception();
	
	printf("-------------key interrypt test--------------");
	
	return 0;
}