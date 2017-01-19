#include "stdio.h"
#include "int.h"
#include "main.h"

int main(void)
{
	volatile int i,j;				//如果不加valatile那个延时就不起作用了
	uart_init();
	struct rtc_time t2;
	struct rtc_time t1 = 
	{
		.year = 2016,
		.month = 5,
		.day = 17,
		.hour = 13,
		.minute = 31,
		.second = 12,
		.dayweek = 2,
	};
	rtc_set_time(&t1);
	
	
	printf("-----RTC interrypt test-------");
	while(1)
	{
		rtc_get_time(&t2);
		printf("--time: %d:%d:%d:%d:%d:%d:%d--", t2.year, t2.month, t2.day, t2.hour, t2.minute, t2.second, t2.dayweek);
		for(i=0; i<1000; i++)
			for(j=0; j<10000; j++);
	}
	
	
	return 0;
}