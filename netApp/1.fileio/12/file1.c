#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int fd1 = -1, fd2 = -1;			
	
	fd1 = open("1.txt", O_RDWR | O_TRUNC | O_CREAT);
	printf("fd1 = %d.\n", fd1);
	
	close(1);
	fd2 = dup(fd1);
	
	if(-1 == fd1 && -1 == fd2)
	{
		printf("fd2 = %d.\n", fd2);
	}
	else
	{
		printf("This is a text.\n");
	}
	
	

	close(fd1);
	close(fd2);
	
	return 0;
}





