
#include <stdio.h>

typedef char * PCHAR;

//#define pchar （char *）		加了括号就相当于强制类型转换了，括号也是照搬上去的，所以我们要注意是否要加上括号
#define pchar char *

int main (void)
{
	char a = 3, b = 4, c = 5;
	PCHAR p1, p2;
	pchar p3;
	
	p1 = &a;
	p2 = &b;
	
	return 0;
}






























