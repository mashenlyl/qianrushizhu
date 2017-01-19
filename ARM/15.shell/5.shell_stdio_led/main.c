#include "shell.h"

int main (void)
{
	//用来存取命令
	char str[MAX_LINE_LENGTH];
	
	uart_init();
	init_cmdset();
	puts("X210 shell strart");
	
	while(1)						//为了让它一直输出
	{
		init_cmdset();
		puts("\n");
		puts("LYL#");
		
		// 第一步：读取命令
		gets(str);
		
		//第二步：解析命令
		cmd_parse(str);
		//第三步：执行命令
		cmd_exec();
		
		//puts(str);
	}
	
	return 0;
}


































