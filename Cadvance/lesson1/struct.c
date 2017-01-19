#include <stdio.h>

struct Student              //这里只是一个模板来的，既不占用内存，也不什么鬼的 
{
	struct me
	{
		int numm;
		float nn;
	};
	char name[20];
	int num;
	int isMale; 
};  //注意这里定义的是结构体，结构体后面的大括号的地方是需要一个分号来结束的。 

int main (void) 
{ 
	struct Student d[30];  //也是可以定义数组类型的结构体的，就把它当作普通的数组来用就可以了 
	struct Student s1;   //这里就是定义一个结构体变量 
	struct Student s2;
	
	struct Student s = {{11, 11.2}, "nimei", 22, 33};   //结构体是可以这样初始化的，就是按照上面定义的顺序一一对应着就可以了 
	
	s.nn;                     //嵌套的结构体是这样定义的，不是点点点，那样是错的 
                                                    //这样初始化是很好的，字符串都可以直接这样初始化了 
	d[0].name[0] = 'f'; 
	d[0].num = 123; 
	d[1].isMale = 1; 
	s1.name[0] = 'J';   //后面如果这是一个字符串的话，那么就要在后面加上\0,表示的是字符串结束了 
	s1.name[1] = 'i';
	s1.name[2] = '\0';
	s1.num = 333;             //这里就是怎么用上面模版上面已经定义好的变量的。就是结构体的使用了 
	s1.isMale = 1; 
	
	printf("shuzu = %c. d[0].name = %d\n", d[0].name[0], d[0].num); 
	printf("name = %s, num = %d, male = %d.\n", s1.name, s1.num, s1.isMale);  //数组如果是打印的是字符串，就直接写它的变量名就可以了 
	printf("me = %d,,%f ,name = %s.\n", s.numm, s.nn, s.name);  //这里是嵌套的结构体，但是还是一个点，没有用到两个点。 
	                                                             //直接写嵌套里面的元素上来就可以了 
	return 0;
} 

/*
结果是：
shuzu = f. d[0].name = 123
name = Ji, num = 333, male = 1.

*/
