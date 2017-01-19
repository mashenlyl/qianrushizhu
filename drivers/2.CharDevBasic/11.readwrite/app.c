#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

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
	
	// 读写文件
	write(fd, "helloworld", 10);
	read(fd, buf, 10);
	
	
	// 关闭文件
	close(fd);
	printf("close sucess\n");
	
	return 0;
}



























