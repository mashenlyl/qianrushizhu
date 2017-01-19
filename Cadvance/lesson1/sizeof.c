//c语言赋予程序最大的权利，程序员想干什么就干什么，程序员必须对自己的错误负责
//高级语言java，就会对程序做检查，不用自己操心
#include <stdio.h>

int main (void)
{
	int a = 123;
	void *p;			//这里定义是void *类型的
	
	p = &a;
	
	printf("a = %d.\n", *(int *)p);  //先通过强制类型转换，让它知道是int类型的
	printf("a = %f.\n", *(float *)p);	//float强制类型转换，编译器不报错
	printf("a = %d, a = %d.\n", a, a); 
	printf("sizeof(int)     = %d.\n", sizeof(int));			// 4
	printf("sizeof(float)   = %d.\n", sizeof(float));		// 4
	printf("sizeof(double)  = %d.\n", sizeof(double)); 		//8
	
	return 0;
} 
