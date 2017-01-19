#include <stdio.h>

int func(int a, int *p);
int func3(char *p);

int main (void)
{
	//char *charStr = "hello";				//这里是常量来的，是不可以被改变的
	char str[] = "hello";					//这个是数组，可以被改变，所以不会出错
	
	func3(str);
	printf("%s.\n", str);
	
	/*
	//这里就是标准的检查函数是否出错的。
	int a, b = 0 , reset = -1;
	
	a = 21;
	
	reset = func(a, &b);
	
	if(reset == -1)
	{
		printf("error!\n");
	}
	else
	{
		printf("b = %d.\n", b);
	}
	*/
	
	return 0;
}

int func(int a, int *p)
{
	*p = a * 5;
	if(*p > 100)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

int func3(char *p)
{
	*p = 'a';
}































