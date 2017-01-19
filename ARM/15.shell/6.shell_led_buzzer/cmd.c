#include "shell.h"

char cmd[CMD_NUM_PART][CMD_LENGTH_PART];
int cmd_in = -1;


/****************************************命令解析的地方***********************************/

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


/**************************************************具体命令操作的地方****************************/
//输入led命令执行的操作
void do_led(void)
{
	int flag = -1;
	
	//led亮
	if(!strcmp(cmd[1], "on"))
	{
		led_on();
		flag = 1;
	}
	
	//led灭
	if(!strcmp(cmd[1], "off"))
	{
		led_off();
		flag = 1;
	}
	
	//led闪烁
	if(!strcmp(cmd[1], "blink"))
	{
		led_blink();
		flag = 1;
	}
	
	//判断是否执行了以上的操作
	if(-1 == flag)
	{
		puts("error! you can try led on | led off | led blink");
	}
}


//输入buzzer命令执行的操作
void do_buzzer(void)
{
	int flag = -1;
	
	//led亮
	if(!strcmp(cmd[1], "on"))
	{
		buzzer_on();
		flag = 1;
	}
	
	//led灭
	if(!strcmp(cmd[1], "off"))
	{
		buzzer_off();
		flag = 1;
	}
	
	//判断是否执行了以上的操作
	if(-1 == flag)
	{
		puts("error! you can try buzzer on | buzzer off");
	}
}









