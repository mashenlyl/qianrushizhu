#include "shell.h"

int main (void)
{
	//������ȡ����
	char str[MAX_LINE_LENGTH];
	
	uart_init();
	init_cmdset();
	puts("X210 shell strart");
	
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


































