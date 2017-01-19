#include <stdio.h>
#include "mashen.h"

int main (void)
{
	func1();
	int a = func2(2, 3);
	
	printf("a = %d.\n", a);
	
	return 0;
}