#include "shell.h"

char cmd[CMD_NUM_PART][CMD_LENGTH_PART];
int cmd_in = -1;


/****************************************��������ĵط�***********************************/

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
		case 0:						//led
			do_led();
			break;
		case 1:						//lcd
		case 2:						//buzzer
			do_buzzer();	
			break;
		default:
			do_error();
			break;
	}
}


/**************************************************������������ĵط�****************************/
//����led����ִ�еĲ���
void do_led(void)
{
	int flag = -1;
	
	//led��
	if(!strcmp(cmd[1], "on"))
	{
		led_on();
		flag = 1;
	}
	
	//led��
	if(!strcmp(cmd[1], "off"))
	{
		led_off();
		flag = 1;
	}
	
	//led��˸
	if(!strcmp(cmd[1], "blink"))
	{
		led_blink();
		flag = 1;
	}
	
	//�ж��Ƿ�ִ�������ϵĲ���
	if(-1 == flag)
	{
		puts("error! you can try led on | led off | led blink");
	}
}


//����buzzer����ִ�еĲ���
void do_buzzer(void)
{
	int flag = -1;
	
	//led��
	if(!strcmp(cmd[1], "on"))
	{
		buzzer_on();
		flag = 1;
	}
	
	//led��
	if(!strcmp(cmd[1], "off"))
	{
		buzzer_off();
		flag = 1;
	}
	
	//�ж��Ƿ�ִ�������ϵĲ���
	if(-1 == flag)
	{
		puts("error! you can try buzzer on | buzzer off");
	}
}









