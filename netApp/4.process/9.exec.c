#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>


int main(void)
{
	int fd = -1, ret = -1;
	pid_t p1 = -1, p2;
	int status;
	
	p1 = fork();
	
	if(p1 > 0)
	{
		printf("父进程\n");
	}
	else if(p1 == 0)
	{
		char *arg[] = {"ls", "-l", "-a", NULL};
		char *envp[] = {"hello", "world", NULL};
		printf("子进程\n");
		printf("pid = %d\n", getpid());
		//execl("/bin/ls", "ls", "-l", "-a", NULL);
		//execv("/bin/ls", arg);
		//execlp("ls", "ls", "-l", "-a", NULL);
		//execvp("./hello", arg);
		execvpe("./hello", arg, envp);
		return 0;
	}
	else
	{
		printf("error\n");
		return -1;
	}
	
	return 0;
}