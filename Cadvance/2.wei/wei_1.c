#include <stdio.h>

int main (void)
{
	int a = 0x1223ffad;				//这里使用的是位异或的特性
	int b = 0x0000ff00;				//想取反的话就用1异或，不变就是用0
	int c;
	
	c = a ^ b;						//位异或
	
	printf("c = %x.\n", c);			//122300ad.
	
	/*
	int a = 0x1223ffad;				//这里使用的是位或的特性来做的
	int b = 0xff000000;				//如果想置1的话就用1位，不变的话就用零来做就可以了
	int c;
	
	c = a | b;						//位或
	
	printf("c = %x.\n", c);			//ff23ffad.	
	*/
	
	/*
	int a = 0x1223ffad;				//这里就是用位与的特性来做的
	int b = 0xffff00ff;				//如果你想置0的话就用0位与，不变的话就用1；
	int c;
	
	c = a & b;						//位与
	
	printf("c = %x.\n", c);			//122300ad
	*/
	return 0;
}




















