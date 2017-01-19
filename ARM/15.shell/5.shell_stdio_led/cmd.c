#include "shell.h"

char cmd[CMD_NUM_PART][CMD_LENGTH_PART];
int cmd_in = -1;

//初始化命令
//这里一个函数，用来初始化命令行的
void init_cmdset(void)
{
	memset((char *)g_cmdset, 0, CMD_NUM);
	strcpy(g_cmdset[0], led);
	strcpy(g_cmdset[1], lcd);
	strcpy(g_cmdset[2], pwm);
	
	memset((char *)cmd, 0, CMD_NUM_PART);
}

// 第二步：解析命令
void cmd_parse(char *str)
{
	int i;
	
	//把输入的命令分割成几个部分来处理
	cmd_division(cmd, str);
	
	cmd_in = -1;
	//判断命令中的主命令
	for(i=0; i<CMD_NUM; i++)
	{
		//解析完命令就直接处理命令了
		if(!(strcmp(cmd[0], g_cmdset[i])))
		{
			cmd_in = i;
			break;
		}
	}
}

//输入错误命令打印的信息
void do_error(void)
{
	puts("输入了不正确的命令：");
	puts(cmd[0]);
}

//第三步：执行命令
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

//输入led命令执行的操作
void do_led(void)
{
	puts("do_led");
}












