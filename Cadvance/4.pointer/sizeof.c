//sizeof的作用就是测量在本系统下数据类型占的字节数
#include <stdio.h>
#include <string.h>

void func1(int *p, int b)
{
	printf("*(p+2) = %d.\n", *(p+2));
	printf("b = %d.\n", b);
}

/*
#define dpChar 	char *
typedef char *	*tpChar;
*/

/*
void func(char b[])
{
	printf("b[2] = %d.\n", b[2]);
	//说明这里等价于一个指针变量而已
	printf("sizeof(b) = %d.\n", sizeof(b));				//4
}
*/

int main (void)
{
	//就是可以用指针来传递数组
	int b[4] = {1, 2, 3, 4};
	func1(b, sizeof(b)/sizeof(b[0]));
	
	/*
	dpChar p1,  p2;			//char *p1, p2;
	tpChar p3,  p4;			//char *p3,char *p4;
	//char *p1,这里是指针变量的
	printf("sizeof(p1) = %d.\n", sizeof(p1));				//4
	printf("sizeof(p1) = %d.\n", sizeof(p2));				//1
	printf("sizeof(p1) = %d.\n", sizeof(p3));				//4
	printf("sizeof(p1) = %d.\n", sizeof(p4));				//4
*/
/*
	char b[10] = {1, 2, 3};
	func(b);					//所以这里传参实际上传的是个指针来的
	*/
	
	/*
	int b[100];			//sizeof(b)
	
	printf("sizeof(b) = %d.\n", sizeof(b));					//400,4(int)x100
	*/
	
	/*
	int n=10; 				//sizeof(n)
	
	printf("sizeof(n) = %d.\n", sizeof(n));					//4
	printf("sizeof(int) = %d.\n", sizeof(int));				//4结果是一样的
	*/
	
	/*
	char str[] = "hello";
	char *p=str;  			//sizeof(p)	sizeof(*p)	strlen(p)
	
	//这里的sizeof表示的char *数据结构占的内存的字节数，指针类型的都是占4个字节的
	printf("sizeof(p) = %d.\n", sizeof(p));				//4
	//*p表示的是首元素，并不是str这个整体，想用指针来控制数组，就+1可以了
	printf("sizeof(*p) = %d.\n", sizeof(*p));			//1
	printf("*p = %c.\n", *p);							//h
	//str在下面那里是作为首元素的首地址，这里的p也只是它的地址，由此可知strlen函数也只要它的地址就可以了
	printf("strlen(p) = %d.\n", strlen(p));				//5
	*/
	
	/*
	//第一种
	char str[] = "hello";  //sizeof(str)	sizeof(str[0])	strlen(str)
	
	printf("str[] = %d.\n", sizeof(str));					//6因为字符串后面有个结束符，所以多1
	printf("str[0] = %d.\n", sizeof(str[0]));				//1
	printf("strlen(str) = %d.\n", strlen(str));			//5，这里会自动去除那个结束符的。
	
	*/
	
	return 0;
}





















