#include <stdio.h>
#include <string.h>

// 最大的命令的长度
#define MAX_LINE_LENGTH 			256

//定义了三个命令
#define led 						"led"
#define lcd 						"lcd"
#define pwm 						"pwm"
#define CMD_NUM						3

char g_cmdset[CMD_NUM][MAX_LINE_LENGTH];

//这里一个函数，用来初始化命令行的
void init_cmdset(void)
{
	memset(g_cmdset, 0, CMD_NUM);
	strcpy(g_cmdset[0], led);
	strcpy(g_cmdset[1], lcd);
	strcpy(g_cmdset[2], pwm);
}

int main(void)
{
	//用来存取命令
	char str[MAX_LINE_LENGTH];
	int i;
	
	init_cmdset();
	
	while(1)
	{
		// shell界面
		printf("LYL#");
		
		//清除str变量内的内容以存取新的数据
		memset(str, 0, sizeof(str));
		// 第一步：读取命令
		scanf("%s", str);
		
		// 第二步：解析命令
		for(i=0; i<CMD_NUM; i++)
		{
			//解析完命令就直接处理命令了
			if(!(strcmp(str, g_cmdset[i])))
			{
				printf("输入了合法命令：%s\n", str);
				break;
			}
		}
		
		if(i>=CMD_NUM)
		{
			printf("输入了不正确的命令：%s\n", str);
		}
		
		//第三步：执行命令
		//printf("%s\n", str);
	}
	
	return 0;
}



































