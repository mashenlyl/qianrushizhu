#include <stdio.h>

int main (void)
{
	int ch;
	
	while((ch = getchar()) != EOF)		//ch != EOF 的时候，就执行下面程序
	{
		putchar(ch);
	}
	
	return 0;
}