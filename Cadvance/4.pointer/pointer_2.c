#include <stdio.h>

int main (void)
{
	int *p = NULL;			//首先赋值是NULL
	int a = 10;
	
	p = &a;					//解引用之前赋上指定的值
	
	if(NULL != p)			//之后判断
	{
		*p = 4;
	}
	
	printf("p = %d.\n", *p);
	p = NULL;				//又重新赋值回来
	
	/*
	int *p;
	
	printf("p = %p.\n", (int *)0);		//上次栈使用时遗留下来的值
	
	*p = 4;						//Segmentation fault (core dumped)触发段错误
	
	printf("p = %p.\n", NULL);	//(void *)0 = NULL
	*/
	
	return 0;
}