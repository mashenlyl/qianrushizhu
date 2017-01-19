#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int fd = 0, count = 0, i = 20;			
	char buf[40] = {0};
	char writebuf[40] = "I LOVE LINUX";

	fd = open("a.txt", O_RDWR | O_CREAT | O_TRUNC);
	if(-1 == fd)
	{
		printf("打开文件失败");
	}
	else
	{
		printf("打开文件成功，fd = %d.\n", fd);
	}
	
	while(1)
	{
		lseek(fd, i, SEEK_SET);
		
		count = write(fd, writebuf, strlen(writebuf));
		if(-1 == count)
		{
			printf("写入文件失败\n");
			perror("write");
			_exit(-1);
		}
		else
		{
			printf("写入文件成功，一共写了%d个字节.\n", count);
		}
		
		// 延迟1秒
		sleep(1);
		i += 20;
	}

	
#if 0
	count = read(fd, buf, 30);
	if(-1 == count)
	{
		printf("读取文件失败\n");
	}
	else
	{
		printf("读取文件成功，一共读取了%d个字节.\n", count);
	}
#endif
	
	close(fd);
	
	return 0;
}






























