#include "shell.h"

//��ʼ������
//����һ��������������ʼ�������е�
void init_cmdset(void)
{
	memset((char *)g_cmdset, 0, CMD_NUM);
	strcpy(g_cmdset[0], led);
	strcpy(g_cmdset[1], lcd);
	strcpy(g_cmdset[2], pwm);
}

// �ڶ�������������
void cmd_parse(char *str)
{
	int i;
	
	for(i=0; i<CMD_NUM; i++)
	{
		//�����������ֱ�Ӵ���������
		if(!(strcmp(str, g_cmdset[i])))
		{
			puts("�����˺Ϸ����");
			puts(str);
			break;
		}
	}
	if(i>=CMD_NUM)
	{
		puts("�����˲���ȷ�����");
		puts(str);
	}
}

//��������ִ������
void cmd_exec(void)
{
	
}














