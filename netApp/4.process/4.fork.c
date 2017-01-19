#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	pid_t p1 = -1;
	
	printf("hello1\n");
	printf("pid = %d\n", getpid());
	
	p1 = fork();
	
	printf("p1 = %d\n", p1);
	printf("hello2\n");
	
	if(p1 < 0)
	{
		printf("error\n");
		return -1;
	}
	else if(p1 == 0)
	{
		printf("子进程\n");
		printf("pid = %d\n", getpid());
		printf("ppid = %d\n", getppid());
	}
	else
	{
		printf("p1 = %d\n", p1);
		printf("父进程\n");
		printf("pid = %d\n", getpid());
		printf("ppid = %d\n", getppid());
	}
	
	printf("end\n");
	
	return 0;
}
