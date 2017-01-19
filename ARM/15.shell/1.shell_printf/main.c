#include <stdio.h>
#include <string.h>

// 最大的命令的长度
#define MAX_LINE_LENGTH 			256

int main(void)
{
	//用来存取命令
	char str[MAX_LINE_LENGTH];

	
	while(1)
	{
		// shell界面
		printf("LYL#");
		
		//清除str变量内的内容以存取新的数据
		memset(str, 0, sizeof(str));
		// 第一步：读取命令
		scanf("%s", str);
		
		// 第二步：解析命令
		
		//第三步：执行命令
		printf("%s\n", str);
	}
	
	return 0;
}



































