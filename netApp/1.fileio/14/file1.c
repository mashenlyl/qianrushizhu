#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	FILE* fd = NULL;
	int count = -1;
	char buf[20] = "I LOVE LINUX!";
	
	// 打开文件，使用fopen来打开文件，w+是可读可写，没有文件就创建文件，有文件就清空文件；
	fd = fopen("1.txt", "w+");
	
	// 写文件
	count = fwrite(buf, sizeof(char), strlen(buf), fd);
	if(-1 == count)
	{
		perror("fwrite");
		_exit(-1);
	}
	else
	{
		printf("count = %d.\n", count);
	}
	
	// 关闭文件
	fclose(fd);
	
	return 0;
}


