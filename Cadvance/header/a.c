#include <stdio.h>
#include "a.h"					//头文件包含，相当于在原处展开，说明这是我自己写的

int main (void)
{
	int a, b, c, d;
	
	a = 10;
	b = 20;
	
	c = add(a,b);
	d = sub(a,b);
	
	printf("c = %d.\n", c);
	printf("d = %d.\n", d);
	
	return 0;
}


















