#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/time.h>
#include <poll.h>


int main(void)
{
	struct pollfd lylfds[2] = {0};
	//int fd = -1, ret = -1;
	int fd = -1, ret = -1;
	//char buf[30];
	char buf[100];
	
	fd = open("/dev/input/mouse1", O_RDONLY);
	if (fd < 0)
	{
		perror("open:");
		return -1;
	}
	/*
	fd = open("/dev/input/mouse1", O_RDONLY);
	if(fd < 0)
	{
		perror("open");
		return -1;
	}
	*/
	
	// 初始化我们的pollfd
	lylfds[0].fd = 0;			// 键盘
	lylfds[0].events = POLLIN;	// 等待读操作
	
	lylfds[1].fd = fd;			// 鼠标
	lylfds[1].events = POLLIN;	// 等待读操作
	/*
	lylfds[0].fd = 0;
	lylfds[0].events = POLLIN;
	lylfds[0].fd = fd;
	lylfds[1].events = POLLIN;
	*/
	
	//判断接收的参数
	// 传参给select函数，进行绑定了
	ret = poll(lylfds, fd+1, 10000);
	printf("ret = %d\n", ret);
	if(ret == 0)
	{
		printf("超时了\n");
	}
	else if(ret < 0)
	{
		perror("select");
	}
	else
	{
		// 判断键盘的
		if(lylfds[0].events == lylfds[0].revents)
		{
			memset(buf, 0, sizeof(buf));
			read(0, buf, 10);
			printf("键盘是：[%s]\n", buf);
		}
			
		if(lylfds[1].events == lylfds[1].revents)
		{
			memset(buf, 0, sizeof(buf));
			read(fd, buf, 10);
			printf("鼠标是：[%s]\n", buf);
		}
	}
	
	return 0;
}