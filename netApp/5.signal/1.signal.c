#include <stdio.h>
#include <signal.h>

void func(int sig)
{
	printf("the signal number is %d\n", sig);
}

int main(void)
{
	struct sigaction act;
	act.sa_handler = func;
	printf("开始\n");
	//signal(SIGINT, func);
	sigaction(SIGINT, &act, NULL);
	while(1);
	printf("结束\n");
	
	return 0;
}