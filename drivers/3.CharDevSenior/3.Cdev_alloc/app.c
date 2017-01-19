#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define NAME 	"/dev/test"

char buf[100];

int main(void)
{
	int fd = -1;
	
	// 打开文件
	fd = open(NAME, O_RDWR);
	if (fd < 0)
	{
		perror("open");
		return -1;
	}
	printf("open sucess\n");
	
	//sleep(4);
	
	while(1)
	{
		memset(buf, 0, sizeof(buf));
		printf("请输入on(led亮) | off(led灭) | quit(退出)\n");
		scanf("%s", buf);
		if (!strcmp(buf, "on"))
		{
			write(fd, "1", 1);
		}
		else if(!strcmp(buf, "off"))
		{
			write(fd, "0", 1);
		}
		else if(!strcmp(buf, "quit"))
		{
			break;
		}
	}
	
	// 关闭文件
	close(fd);
	printf("close sucess\n");
	
	return 0;
}





