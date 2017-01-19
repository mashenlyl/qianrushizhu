#include "stdio.h"
#include "int.h"
#include "main.h"

int main(void)
{
	volatile int i,j;				//如果不加valatile那个延时就不起作用了
	uart_init();
	
	//初始化还要涉及到硬件的初始化，就比如按键那里，我们也要对按键先进行初始化
	isr_set_alarm();
	//绑定异常向量表的
	system_init_exception();
	//绑定硬件
	intc_setvectaddr(NUM_RTC_ALARM, isr_rtc_alarm);
	//使能中断
	intc_enable(NUM_RTC_ALARM);
	
	struct rtc_time t2;
	
	printf("-----RTC interrypt test-------");
	while(1)
	{
		rtc_get_time(&t2);
		printf("--time(s): %d", t2.second);
		for(i=0; i<1000; i++)
			for(j=0; j<10000; j++);
	}
	
	
	return 0;
}