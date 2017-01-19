#include <stdio.h>

struct Male   //这里是定义结构体 
{
	int age;
	char name[20];
	int baskerball; 
}; 

struct Imale       //但是结构体就可以用这里的全部，用法就是s1.age 
{
	int age;
	char name[20];
	int play; 
};

union human       //这里是共用体的定义了 
{
	struct Male s;    //结构体就是这样定义的，就是相当于是一种数据类型，int型什么的 
	struct Imale h;   //也就是说只用到这么多种情况中的一个，只能选择男的或者是女的。 
}; 

int main (void)
{
	union human s1;    //s1就表示是一个共用体了 
	union human s2;     
	
	s1.s.age = 3;    //这里就是共用体的用法了 ,s1中的s，s中的name 
	s2.h.age = 2;
	
	printf("s = %d, h = %d.\n", s1.s.age, s2.h.age);   //这里的结果是2，说明共用体的就是一个东西，而且是以最后结果为主 
	return 0;
} 






















