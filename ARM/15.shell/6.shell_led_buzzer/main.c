#include "shell.h"

static void hardware_init(void)
{
	led_init();						//led��ʼ��
	pwm_init();			//buzzer��ʼ��
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


































