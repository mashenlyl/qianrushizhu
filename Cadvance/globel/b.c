//函数被a.c引用，在这里定义
#include <stdio.h>			//写上这句的时候就不会报警告

extern int g_a;				//声明，告诉编译器我在不是本文件但是是同一程序定义一个全局变量
							//extern是外部的意思
int bb(void)
{
	printf("This is main in c.c\n");
	printf("This is g_a= %d.\n", g_a);
	
	return 0;
}





































