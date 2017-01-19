#include <stdio.h>

void fun1(void);

int g_a;

int main (void)
{
	printf("g_a = %d.\n", g_a);		//0
	fun1();
	printf("g_a = %d.\n", g_a);    //100   值改变了，因为它是全局变量
	
	g_a += 1;
	printf("g_a = %d.\n", g_a); 
	
	return 0;
}

void fun1(void)
{
	g_a = 100;
}


















