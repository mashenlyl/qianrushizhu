#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/time.h>


int main(void)
{
	fd_set readfd;
	struct timeval tm;
	int fd = -1, ret = -1;
	char buf[30];
	
	fd = open("/dev/input/mouse1", O_RDONLY);
	if(fd < 0)
	{
		perror("open");
	}
	
	//设置fd
	FD_ZERO(&readfd);
	FD_SET(0, &readfd);
	FD_SET(fd, &readfd);
	
	// 设置超时的时间
	tm.tv_sec = 6;
	tm.tv_usec = 0;
	
	//判断接收的参数
	// 传参给select函数，进行绑定了
	ret = select(fd+1, &readfd, NULL, NULL, &tm);
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
		if(FD_ISSET(0, &readfd))
		{
			memset(buf, 0, sizeof(buf));
			read(0, buf, 10);
			printf("键盘是：[%s]\n", buf);
		}
			
		if(FD_ISSET(fd, &readfd))
		{
			memset(buf, 0, sizeof(buf));
			read(fd, buf, 10);
			printf("鼠标是：[%s]\n", buf);
		}
	}
	
	return 0;
}