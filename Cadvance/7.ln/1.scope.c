#include <stdio.h>

int var = 10;

//作用域，相同名字的话，就是看最近的那个变量了，譬如main函数里面就有两个var变量，但是if里面的var更近
//所以if里面就使用if里面定义的var变量了
int main (void)
{
	//加上extern就表明使用全局变量，不加上，var就是一个局部变量来的
	//extern int var;
	//这里的var的作用域就是main函数里面了
	int var = 5;
	
	if(1)
	{
		//这里var的作用域就是if这个大括号里面了
		int var = 3;
		printf("var = %d.\n", var);
	}
	
	printf("var = %d.\n", var);
	
	return 0;
}