#include "cal.h"
#include <stdio.h>

int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

int multiply(int a, int b)
{
	return a * b;
}

int divide(int a, int b)
{
	return a / b;
}

int main(void)
{
	int result;
	struct cal_t p2;
	p2.a = 12;
	p2.b = 3;
	p2.p = divide;
	
	result = caculator(&p2);			//½Ó¿Úº¯Êı
	printf("result = %d.\n", result);
	
	return 0;
}





































