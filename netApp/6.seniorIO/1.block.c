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
	
	printf("开始\n");
	memset(buf, 0, sizeof(buf));
	read(0, buf, 10);
	printf("内容是：[%s]\n", buf);
	
	fd = open("/dev/input/mouse1", O_RDONLY);
	printf("开始\n");
	memset(buf, 0, sizeof(buf));
	read(fd, buf, 10);
	printf("内容是：[%s]\n", buf);
	
	/*
	// 读取鼠标的
	int fd;
	char buf[30];
	
	fd = open("/dev/input/mouse1", O_RDONLY);
	printf("开始\n");
	memset(buf, 0, sizeof(buf));
	read(fd, buf, 10);
	printf("内容是：[%s]\n", buf);
	*/
	
	/*
	// 读取键盘的
	char buf[30];
	
	printf("开始\n");
	memset(buf, 0, sizeof(buf));
	read(0, buf, 10);
	printf("内容是：[%s]\n", buf);
	*/
	
	return 0;
}