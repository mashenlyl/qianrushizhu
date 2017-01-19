//c语言中多个文件的时候，只可以有一个main函数，如果有多个main函数就会出错的
//为了组织上的便利，把c文件分成多个文件，还分多个文件夹
#include <stdio.h>

int g_a = 5;

void func2(void);

int bb(void);				//这是在b.c中定义的函数，现在在a.c中引用
							//编译的时候是这样写的：gcc a.c b.c -o ab,就把两个文件合成一个了
							//执行的时候是：./ab
int main (void)				
{
	int i, j;
	
	i = 18;
	j = 11;
										//float类型的不可以进行取余
	printf("i %% j = %d.\n", i%j);		//这里面要表现出%的话，就要写%%才可以
	printf("This is main in a.c\n");
	bb();					//这里，函数被引用
	func2();
	
	return 0;
}

void func2(void)			//不能在函数里面定义函数
{
	int i = 2;
	
	printf("i = %d.\n", i);
}





















