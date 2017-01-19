#include <stdio.h>

int g_a;				//这是全局变量

int main (void)
{
	int a;				//这是局部变量
	
	printf("a = %d, g_a = %d.\n", a, g_a);
	
	return 0;
}