#include "shell.h"

//初始化命令
//这里一个函数，用来初始化命令行的
void init_cmdset(void)
{
	memset((char *)g_cmdset, 0, CMD_NUM);
	strcpy(g_cmdset[0], led);
	strcpy(g_cmdset[1], lcd);
	strcpy(g_cmdset[2], pwm);
}

// 第二步：解析命令
void cmd_parse(char *str)
{
	int i;
	
	for(i=0; i<CMD_NUM; i++)
	{
		//解析完命令就直接处理命令了
		if(!(strcmp(str, g_cmdset[i])))
		{
			puts("输入了合法命令：");
			puts(str);
			break;
		}
	}
	if(i>=CMD_NUM)
	{
		puts("输入了不正确的命令：");
		puts(str);
	}
}

//第三步：执行命令
void cmd_exec(void)
{
	
}














