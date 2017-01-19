#include "shell.h"
#include "stdio.h"
#include "int.h"

int g_bootdelay = 3;
int g_isgo = 0;

static void hardware_init(void)
{
	led_init();						//led初始化
	pwm_init();						//buzzer初始化
	adc_init();						//adc初始化
	lcd_init();						//lcd初始化
	wd_timer_init();				//看门狗中断初始化
}

void shell_init(void)
{
	uart_init();
	init_cmdset();
	hardware_init();
	puts("X210 shell strart");
}

int main (void)
{
	//用来存取命令
	char str[MAX_LINE_LENGTH];
	
	shell_init();
	
	printf("\n");
	puts("LYL#");
	printf("%d", g_bootdelay);
	while((!g_getc()) && (!g_isgo));
	
	intc_disable(NUM_WDT);
	
	while(1)						//为了让它一直输出
	{
		init_cmdset();
		puts("\n");
		puts("LYL#");
		
		// 第一步：读取命令
		gets(str);
		
		//第二步：解析命令
		cmd_parse(str);
		//第三步：执行命令
		cmd_exec();
		
		//puts(str);
	}
	
	return 0;
}


































