#include "shell.h"

char cmd[CMD_NUM_PART][CMD_LENGTH_PART];
int cmd_in = -1;

//��ʼ������
//����һ��������������ʼ�������е�
void init_cmdset(void)
{
	memset((char *)g_cmdset, 0, CMD_NUM);
	strcpy(g_cmdset[0], led);
	strcpy(g_cmdset[1], lcd);
	strcpy(g_cmdset[2], pwm);
	
	memset((char *)cmd, 0, CMD_NUM_PART);
}

// �ڶ�������������
void cmd_parse(char *str)
{
	int i;
	
	//�����������ָ�ɼ�������������
	cmd_division(cmd, str);
	
	cmd_in = -1;
	//�ж������е�������
	for(i=0; i<CMD_NUM; i++)
	{
		//�����������ֱ�Ӵ���������
		if(!(strcmp(cmd[0], g_cmdset[i])))
		{
			cmd_in = i;
			break;
		}
	}
}

//������������ӡ����Ϣ
void do_error(void)
{
	puts("�����˲���ȷ�����");
	puts(cmd[0]);
}

//��������ִ������
void cmd_exec(void)
{
	switch(cmd_in)
	{
		case 0:
			do_led();
			break;
		case 1:
		case 2:
		default:
			do_error();
			break;
	}
}

//����led����ִ�еĲ���
void do_led(void)
{
	puts("do_led");
}












