#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void func(int sig)
{
	//printf("时间到了 %d\n", sig);
}

void sleep2(unsigned int seconds)
{
	alarm(seconds);
	signal(SIGALRM, func);
	pause();
}

int main(void)
{
	printf("开始\n");
	sleep2(6);
	printf("结束\n");
	
/*
	int ret = -1;
	struct sigaction act;
	act.sa_handler = func;
	printf("开始\n");
	ret = alarm(3);
	sleep(2);
	printf("ret = %d\n", ret);
	ret = alarm(5);
	printf("ret = %d\n", ret);
	sleep(2);
	ret = alarm(3);
	printf("ret = %d\n", ret);
	//signal(SIGINT, func);
	sigaction(SIGALRM, &act, NULL);
	while(1);
	printf("结束\n");
*/
	return 0;
}