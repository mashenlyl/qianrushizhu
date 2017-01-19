#include <stdio.h>

inline int func1(int a, int b);

int main (void)
{
	printf("func1 = %d.\n", func1(2,3));
	
	return 0;
}