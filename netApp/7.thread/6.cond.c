#include <stdio.h>
#include <string.h>
#include <semaphore.h>

char buf[100] = {0};
int flag = 0;
pthread_mutex_t mutex;
pthread_cond_t cond;

void *func(void *arg)
{
	sleep(1);
	while(flag == 0)
	{
		pthread_mutex_lock(&mutex);
		pthread_cond_wait(&cond, &mutex);
		printf("输入了%d个字符\n", strlen(buf));
		pthread_mutex_unlock(&mutex);
		memset(buf, 0, sizeof(buf));
	}
	
}

int main(void)
{
	pthread_t th = -1;
	
	// 创建子线程
	pthread_create(&th, NULL, func, NULL);
	
	// 互斥锁初始化
	pthread_mutex_init(&mutex, NULL);
	
	// 条件变量初始化，注意条件变量需要和互斥锁绑定在一起来使用的
	pthread_cond_init(&cond, NULL);
	
	printf("请输入字符，并以回车结束\n");
	while(1)
	{
		scanf("%s", buf);
		
		if(!strcmp("end", buf))
		{
			printf("输入结束\n");
			flag = 1;
			pthread_cond_signal(&cond);
			break;
		}
		pthread_cond_signal(&cond);
	}
	
	// 等待回收子线程
	printf("等待回收子线程\n");
	pthread_join(th, NULL);
	printf("回收子线程成功\n");
	
	return 0;
}