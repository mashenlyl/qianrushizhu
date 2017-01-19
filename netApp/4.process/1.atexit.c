#include <stdio.h>
#include <stdlib.h>

void func1(void)
{
	printf("func1\n");
}

void func2(void)
{
	printf("func2\n");
}

void func3(void)
{
	printf("func3\n");
}

int main(void)
{
	atexit(func1);
	
	printf("hello\n");
	
	atexit(func2);
	
	printf("end\n");
	
	atexit(func3);
	
	return 0;
}
