#include <stdio.h>

int main (void)
{
	int *p;
	char *p1;
	int a[5] = {256, 16, 23, 22, 34};
	
	p = a;
	p1 = (char *)p;
	
	printf("*(p+1) = %d.\n", *(p+1));
	printf("*(p1+1) = %d.\n", *(p1+1));			//这里就相当于是移动了一个字节而已，就是移动8位
	printf("*((char *)p+1) = %d.\n", *((char *)p+1));		//这里和上面一样
	//下面这个就复杂了，应该是首先把它转换成int类型的，然后加1，之后转成指针类型的，最后指向它内存的地址
	printf("*(int *)((unsigned int)p+1) = %d.\n", *(int *)((unsigned int)p+1));
	
	/*
	int *p;
	int a[5] = {10, 11, 23, 22, 34};
	
	p = a;										//a做右值的时候，就表示首元素的地址
	
	printf("a[3] = %d.\n", a[3]);
	printf("*(a+3) = %d.\n", *(a+3));
	printf("*(p+3) = %d.\n", *(p+3));			//这些都是等同的。
	*/
	
	return 0;
}















