#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int fd1 = -1, fd2 = -1, count1 = 0, count2 = 0;			//文件描述符(file descriptor)；count表示成功读取或者写入了多少个字节数
	char buf[40] = {0};
	char writebuf[40] = "I LOVE LINUX";
	
	// 1. 打开文件，int open(const char *pathname, int flags);返回值是文件描述符（-1表示失败，非0表示成功）
	fd1 = open("1.txt", O_RDWR | O_TRUNC | O_CREAT);
	close(1);
	fd2 = dup(fd1);
	if(-1 == fd1 && -1 == fd2)
	{
		printf("打开文件失败\n");
		_exit(-1);
	}
	else
	{
		printf("打开文件成功，fd1 = %d.\n", fd1);
		printf("打开文件成功，fd2 = %d.\n", fd2);
	}
	
	// 2. 读写文件
	// 写文件：ssize_t write(int fd, const void *buf, size_t count)
	// 写文件也需要文件描述符fd，buf用来存放要写进去的内容，count表示成功写入了多少数据；失败也是返回-1
#if 0
	while(1)
	{
		count1 = write(fd1, "gggg", 2);
		count2 = write(fd2, "bb", 2);
		if(-1 == count1 && -1 == count2)
		{
			printf("写入文件失败\n");
			perror("write");
		}
		else
		{
			printf("count1 = %d\n", count1);
			printf("count2 = %d\n", count2);
		}
		sleep(1);
	}
	
#endif
	
	// 利用lseek把文件指针跳转到开头的地方
	lseek(fd1, 0, SEEK_SET);
	
	// 读文件：ssize_t read(int fd, void *buf, size_t count);
	// 需要传入文件描述符，buf把读出来的内容放到buf中，count是要读取的字节数；返回值是成功读取了多少个字节的数据
	// 如果失败还是返回-1；成功返回的是非零的数
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
	
	// 3. 关闭文件；关闭文件的原型：int close(int fd)；返回零表示成功；返回-1表示失败；
	close(fd1);
	close(fd2);
	
	return 0;
}





