#include "shell.h"
#include "stdio.h"
#include "int.h"

int g_bootdelay = 3;
int g_isgo = 0;

static void hardware_init(void)
{
	led_init();						//led��ʼ��
	pwm_init();						//buzzer��ʼ��
	adc_init();						//adc��ʼ��
	lcd_init();						//lcd��ʼ��
	wd_timer_init();				//���Ź��жϳ�ʼ��
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
	//������ȡ����
	char str[MAX_LINE_LENGTH];
	
	shell_init();
	
	printf("\n");
	puts("LYL#");
	printf("%d", g_bootdelay);
	while((!g_getc()) && (!g_isgo));
	
	intc_disable(NUM_WDT);
	
	while(1)						//Ϊ������һֱ���
	{
		init_cmdset();
		puts("\n");
		puts("LYL#");
		
		// ��һ������ȡ����
		gets(str);
		
		//�ڶ�������������
		cmd_parse(str);
		//��������ִ������
		cmd_exec();
		
		//puts(str);
	}
	
	return 0;
}


































