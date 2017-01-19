#include <stdio.h>

int main (void)
{
	//指针的使用有三步：定义指针变量，关联指针变量，解引用
	int a = 23;
	int *p;				//定义指针变量
	
	p = &a;				//关联指针变量
	
	printf("*p = %d.\n", *p);		//解引用
	
	return 0;
}