#include <stdio.h>
#include <string.h>
#include <semaphore.h>

char buf[100] = {0};
sem_t sem;
int flag = 0;

void *func(void *arg)
{
	sem_wait(&sem);
	// 子线程
	while(flag == 0)
	{
		// 等待接收信号
		printf("输入了%d个字符\n", strlen(buf));
		memset(buf, 0, sizeof(buf));
		sem_wait(&sem);
	}
	
}

int main(void)
{
	pthread_t th = -1;
	
	
	// 创建子线程
	pthread_create(&th, NULL, func, NULL);
	
	// 信号量初始化
	sem_init(&sem, 0, 0);
	
	printf("请输入字符，并以回车结束\n");
	while(1)
	{
		scanf("%s", buf);
		if(!strcmp("end", buf))
		{
			printf("输入结束\n");
			flag = 1;
			// 发信号要子进程不要堵塞在那里了
			sem_post(&sem);
			break;
		}
		
		// 发信号给子线程
		sem_post(&sem);
	}
	
	// 等待回收子线程
	printf("等待回收子线程\n");
	pthread_join(th, NULL);
	printf("回收子线程成功\n");
	
	return 0;
}