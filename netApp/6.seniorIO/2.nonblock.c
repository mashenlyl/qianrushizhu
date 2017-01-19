#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(void)
{
	
	//先读取键盘，然后再读鼠标
	char buf[30];
	int fd;
	int ret = -1;
	printf("开始\n");
	ret = fcntl(0, F_GETFL);
	ret |= O_NONBLOCK;
	fcntl(0, F_SETFL, ret);
	fd = open("/dev/input/mouse1", O_RDONLY | O_NONBLOCK);
	while(1)
	{
		memset(buf, 0, sizeof(buf));
		ret = read(0, buf, 10);
		if(ret > 0)
		{
			printf("键盘是：[%s]\n", buf);
			break;
		}
		
		memset(buf, 0, sizeof(buf));
		ret = read(fd, buf, 10);
		if(ret > 0)
		{
			printf("鼠标是：[%s]\n", buf);
			break;
		}
		
	}
	
	/*
	// 读取鼠标的
	int fd;
	char buf[30];
	
	fd = open("/dev/input/mouse1", O_RDONLY | O_NONBLOCK);
	printf("开始\n");
	memset(buf, 0, sizeof(buf));
	read(fd, buf, 10);
	printf("内容是：[%s]\n", buf);
	*/
	
	/*
	// 读取键盘的
	char buf[30];
	int ret = -1;
	
	printf("开始\n");
	memset(buf, 0, sizeof(buf));
	ret = fcntl(0, F_GETFL);
	ret |= O_NONBLOCK;
	fcntl(0, F_SETFL, ret);
	read(0, buf, 10);
	printf("内容是：[%s]\n", buf);
	*/
	
	return 0;
}
