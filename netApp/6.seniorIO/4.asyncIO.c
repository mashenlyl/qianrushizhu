#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

int fd = -1;

void func(int sig)
{
	char buf[30];
	
	if(sig == SIGIO)
	{
		memset(buf, 0, sizeof(buf));
		read(fd, buf, 10);
		printf("鼠标是：[%s]\n", buf);
	}
}

int main(void)
{
	// 读取鼠标的
	int ret = -1;
	char buf[30];
	fd = open("/dev/input/mouse1", O_RDONLY);
	
	// 把鼠标文件设置为异步IO形式
	ret = fcntl(fd, F_GETFL);
	ret |= O_ASYNC;
	fcntl(fd, F_SETFL, ret);
	
	// 把读键盘的进程设置为主进程
	fcntl(fd, F_SETOWN, getpid());
	
	// 注册signal
	signal(SIGIO, func);
	
	while(1)
	{
		memset(buf, 0, sizeof(buf));
		read(0, buf, 10);
		printf("键盘是：[%s]\n", buf);
	}
	return 0;
}