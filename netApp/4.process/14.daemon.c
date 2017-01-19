#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


void creat_daemon(void);

int main(void)
{
	pid_t p1 = -1;
	
	p1 = fork();
	
	if(p1 > 0)
	{
		printf("父进程\n");
		return 0;
	}
	else if(p1 == 0)
	{
		creat_daemon();
		
		//最后这里忘记让它一直执行下去了
		while(1)
		{
			printf("this is ..\n");
		}
	}
	else
	{
		printf("error\n");
		return -1;
	}
	
	return 0;
}

void creat_daemon(void)
{
	int i = 0;
	pid_t pid = -1;
	
	// 第一步：设置新会话
	pid = setsid();
	if(pid < 0)
	{
		perror("setpid");
	}
	
	// 第二步，改变目录
	chdir("/");
	
	// 第三步：关闭所有的文件描述符,sysconf函数可以知道最大的文件描述符
	for(i=0; i<=sysconf(_SC_OPEN_MAX); i++)
	{
		close(i);
	}
	
	// 第四步：把0、1、2定位到/dev/null文件上
	open("dev/null", O_RDONLY);
	open("dev/null", O_RDONLY);
	open("dev/null", O_RDONLY);
	
	// 第五步：设置umask的值为0002
	umask(0002);
}




















