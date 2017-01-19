#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>



int main(void)
{
	int fd = -1, ret = -1;
	pid_t p1 = -1;
	
	p1 = fork();
	
	if(p1 > 0)
	{
		fd = open("1.txt", O_RDWR | O_APPEND);
		if(fd < 0)
		{
			perror("open");
			return -1;
		}
		printf("父进程\n");
		ret = write(fd, "hellolll", 8);
		
		if(ret < 0)
		{
			perror("write");
			return -1;
		}
		printf("ret = %d\n", ret);
		printf("pid = %d\n", getpid());
	}
	else if(p1 == 0)
	{
		fd = open("1.txt", O_RDWR | O_APPEND);
		if(fd < 0)
		{
			perror("open");
			return -1;
		}
		ret = write(fd, "worldhh", 7);
		printf("ret = %d\n", ret);
		
		if(ret < 0)
		{
			perror("write");
			return -1;
		}
		printf("子进程\n");
		printf("ppid = %d\n", getppid());
	}
	else
	{
		printf("error\n");
		return -1;
	}
	
	return 0;
}