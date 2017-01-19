#include "shell.h"

// 最大的命令的长度
#define MAX_LINE_LENGTH 			256

int main (void)
{
	//用来存取命令
	char str[MAX_LINE_LENGTH];
	
	uart_init();
	puts("X210 shell strart");
	
	while(1)						//为了让它一直输出
	{
		puts("\n");
		puts("LYL#");
		gets(str);
		puts(str);
	}
	
	return 0;
}


































