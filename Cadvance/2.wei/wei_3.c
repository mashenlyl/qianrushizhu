//置1用|，置0用&，构造数用左移

#include <stdio.h>

int main (void)
{
	//8、用C语言给一个寄存器的bit7～bit17赋值937，同时给bit21～bit25赋值17.
	//这里面就是同时把要清零的那几位清零掉，然后赋值
	unsigned int a = 0xc305bad3;
	
	a &= ((~(0x7ff<<7)) & (~(0x1f<<21)));		//这里如果用|，就全部都是1了，所以要用&，把要置0的置0
	a |= ((937<<7) | (17<<21));
	
	printf("a = 0x%x.\n", a);			//a = 0xc225d4d3.
	
	/*
	//8、用C语言给一个寄存器的bit7～bit17赋值937，同时给bit21～bit25赋值17.
	//同时赋值和一个个来赋值是一样的，就是多了几步而已
	unsigned int a = 0xc305bad3;
	
	a &= (~(0x7ff<<7));
	a |= (937<<7);
	a &= (~(0x1f<<21));
	a |= (17<<21);
	
	printf("a = 0x%x.\n", a);			//a = 0xc225d4d3.
	*/
	
	/*
	//7、用C语言将一个寄存器的bit7～bit17中的值加17（其余位不受影响）。
	//要加值，就要把那几位的数字取出来，然后把那几位清零&，之后右移，相加，左移，再置1 |
	unsigned int a = 0xc305bad3;
	unsigned int tmp;
	
	tmp = a & (0x7ff<<7);
	a &= (~(0x7ff<<7))；
	tmp >>= 7;
	tmp += 17;
	tmp <<= 7;
	a |= tmp;
	
	printf("a = 0x%x.\n", a);			//a = 0xc305c353
	*/
	
	/*
	//6、用C语言给一个寄存器的bit7～bit17赋值937（其余位不受影响）。
	//要赋值就需要把要赋值的那几位清零&，然后把需要赋值的数左移到那几位上就可以了
	unsigned int a = 0xc305bad3;
	
	a &= (~(0x7ff<<7));
	a |= (937<<7);
	
	printf("a = 0x%x.\n", a);			//a = 0xc305d4d3.
	*/
	
	/*
	//5、给定一个整形数a，取出a的bit3~bit8。
	//要取出这个数，首先要把其他位清零&，之后右移就可以得出那个数了
	unsigned int a = 0xc305bad3;
	unsigned int tmp;
	
	tmp = a & (0x3f<<3);
	tmp >>= 3;
	
	printf("tmp = 0x%x.\n", tmp);
	*/
	
	/*
	//4、给定一个整形数a，清除a的bit15~bit23，保持其他位不变。
	unsigned int a = 0xc305bad3;
	
	a &= ~(0x1ff<<15);
	
	printf("a = 0x%x.\n", a);			//a = 0xc3003ad3.
	*/
	
	/*
	//3、给定一个整型数a，清除a的bit15，保证其他位不变。
	unsigned int a = 0xc305bad3;
	
	a &= ~(1<<15);
	
	printf("a = 0x%x.\n", a);			//a = 0xc3053ad3.
	*/
	
	/*
	//2、给定一个整形数a，设置a的bit3~bit7，保持其他位不变
	unsigned int a = 0xc3057ad3;
	
	a |= (0x1f<<3);
	
	printf("a = 0x%x.\n", a);			//a = 0xc3057afb.
	*/
	
	/*
	//1、给定一个整型数a，设置a的bit3，保证其他位不变
	//设置就是设置为1的意思，清除就是清除为0的意思
	unsigned int a = 0xc3057ad3;
	
	a |= (1<<3);
	
	printf("a = 0x%x.\n", a);			//a = 0xc3057adb.
	*/
	
	return 0;
}



























