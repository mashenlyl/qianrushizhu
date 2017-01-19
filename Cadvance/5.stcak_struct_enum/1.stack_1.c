#include <stdio.h>

int *func(void)
{
	int a = 10;
	return &a;
}

int main (void)
{
	int a = 10;
	int *p = NULL;
	p = func();
	printf("p = %p.\n", p);
	printf("p = %p.\n", *p);
	
	return 0;
}






























