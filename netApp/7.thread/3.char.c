#include <stdio.h>
#include <string.h>

int main(void)
{
	char buf[100] = {0};
	
	printf("请输入字符，并以回车结束\n");
	while(1)
	{
		scanf("%s", buf);
		if(!strcmp("end", buf))
		{
			printf("输入结束\n");
			break;
		}
		
		printf("输入了%d个字符\n", strlen(buf));
	}
	
	return 0;
}