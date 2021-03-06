#include <stdio.h>

//这里就是要把数字x的第n位（bit（n-1）位）置为1
//1U就表示的是无符号的1，宏定义可以传参的
#define SET_BIT(x,n)	(x | 1U<<(n-1))

//这里就是要把数字x的第n位（bit（n-1）位）清零
#define CLEAR_BIT(x,n)	(x & ~(1U<<(n-1)))

//这里就是要把数字x的第n到m位置为1(n是低位，m是高位)
//就是先把0取反就可以得到很多的1，然后左移就得到那么多个0，再取反就可以得到你想要的1的个数了
//最后左移位或就可以置1了
#define SET_BITS(x,n,m)	(x | ~(~0U<<(m-n+1))<<(n-1))

//截取变量的部分连续位。(就是取出的意思)
//其实和上面那里是差不多的，后面那一大部分都是为了确定需要多少个1
//最后记得右移，为了得出那个数字
#define GET_BIT(x,n,m)	(x & ~(~0U<<(m-n+1))<<(n-1)) >>(n-1)

int main (void)
{
	unsigned int a = 0xfffffabf;
	unsigned int b;
	
	b = GET_BIT(a,5,12);				//上面那里就是ab
	
	printf("b = 0x%x.\n", b);			//b = 0xab.
	
	/*
	unsigned int a = 0x0;
	unsigned int b;
	
	b = SET_BITS(a,5,8);
	
	printf("b = 0x%x.\n", b);			//b = 0xf0.
	*/
	
	/*
	unsigned int a = 0xf;
	unsigned int b = 0;
	
	b = CLEAR_BIT(a,4);
	
	printf("b = 0x%x.\n", b);			//b = 0x7.
	*/
	
	/*
	unsigned int a = 0;
	unsigned int b = 0;
	
	b = SET_BIT(a,4);
	
	printf("b = 0x%x.\n", b);			//b = 0x8.
	*/
	
	return 0;
}























