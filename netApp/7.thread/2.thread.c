#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int fd = -1;
char buf[30];

void *func(void *arg)
{
	// 子线程
	while(1)
	{
		memset(buf, 0, sizeof(buf));
		read(fd, buf, 10);
		printf("鼠标内容是：[%s]\n", buf);
	}
	
}

int main(void)
{
	pthread_t th = -1;

	fd = open("/dev/input/mouse1", O_RDONLY);
	pthread_create(&th, NULL, func, NULL);
	
	// 主线程，读键盘
	while(1)
	{
		memset(buf, 0, sizeof(buf));
		read(0, buf, 10);
		printf("键盘内容是：[%s]\n", buf);
	}

	return 0;
}