#include <stdio.h>

int main (void)
{
	//const和指针之间的关系就一共有四种
	//记忆方法：const在*号前面，p就是变量，指向常量
	//const在*号后面，p是常量，指向的是变量
	//第一种：指针是个变量，它所指向的是个常量来的
	const int *p1;
	//第二种：和第一种是一样的
	int const *p2;
	//第三种，指针是常量，它所指向的是个变量来的
	int * const p3;
	//第四种：指针是常量，它所指向的是个常量来的
	const int * const p4;
	
	*p1 = 4;			//error: assignment of read-only location ‘*p1’
	
	*p2 = 4;			//error: assignment of read-only location ‘*p2’
	
	p3 = 0;				// error: assignment of read-only variable ‘p3’
	*p3 = 4;
	
	p4 = 0;
	*p4 = 4;			//error: assignment of read-only location ‘*p4’
	
	return 0;
}
























