#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int cal_len(char *pathname)
{
	int fd = -1, len = 0;
	
	fd = open(pathname, O_RDWR);
	len = lseek(fd, 0, SEEK_END);
	printf("文件长度为：%d\n", len);
	close(fd);
	
	return len;
}

int main(int argc, char *argv[])
{
	if(argc <= 1)
	{
		printf("usage: %s filename\n", argv[0]);
		return -1;
	}
	cal_len(argv[1]);
	
	return 0;
}

































