#include <stdio.h>

int main (void)
{
	//就是想让哪位是1就移位就可以了，加上位或来拼成那个数，而且这样的方法可以很容易就可以看出来做了什么
	//这种移位和位或加位取反的方法就是针对哪些1多0少的
	unsigned int a;
	
	a = ~((0x3<<5)|(0x7<<21));
	
	printf("a = %x.\n", a);				//0xff1fff9f
	
/*
	//这种移位和位或的方法是针对那些1少0多
	unsigned int a;
	
	a = ((0x3<<4)|(0x7<<20));		
	
	printf("a = %x.\n", a);					//a = 700030.
*/

	return 0;
}













