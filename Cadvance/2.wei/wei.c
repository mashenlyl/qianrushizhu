#include <stdio.h>

int main (void)
{
	unsigned int r = 0x80000000;			//这里就是1000.。31个零，也就是int类型的最高位了
	int w = 0x80000000;
	int a = 45;
	int b, c, d, e;
	
	b = !!a;				//这是逻辑上的非，逻辑上的东西除了0之外其他都是一
	c = ~~a;				//这是位运算，就是按照一位一位的进行取反运算
	
	d = !(!a);				//他们和上面的是同一个意思来的
	e = ~(~a);
	
	printf("r = %x.\n", r);
	printf("w = %x.\n", w);		
	
	r = r>>1;				//这里右移了一位，因为它是没有符号位的，所以左边就是补上0
	w = w>>1;				//有符号位的数，右移的时候是补上符号位的1
	
	printf("r = %x.\n", r);
	printf("w = %x.\n", w);
	printf("b = %d.\n", b);
	printf("c = %d.\n", c);
	printf("d = %d.\n", d);
	printf("e = %d.\n", e);
	
	return 0;
}
























