#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(void)
{
	pid_t pid = -1;
	char buf[30];
	int fd;
	
	pid = fork();
	
	if(pid == 0)
	{
		// 子进程，读鼠标
		fd = open("/dev/input/mouse1", O_RDONLY);
		while(1)
		{
			memset(buf, 0, sizeof(buf));
			read(fd, buf, 10);
			printf("鼠标内容是：[%s]\n", buf);
		}
	}
	else if(pid < 0)
	{
		// 出错了
		perror("fork");
	}
	else
	{
		// 父进程，读键盘
		while(1)
		{
			memset(buf, 0, sizeof(buf));
			read(0, buf, 10);
			printf("键盘内容是：[%s]\n", buf);
		}
	}

	return 0;
}