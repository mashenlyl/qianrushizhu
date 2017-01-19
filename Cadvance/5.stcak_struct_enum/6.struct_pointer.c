//总结：#pragma pack(n)是结构体内每个元素都以这样的字节数来对齐，但是n大于4之后就不起什么作用了
//__attribute__((packed))就是以1字节对齐的形式
//__attribute__((aligned(1)))这个是以整体1,2,4,8,16这样的字节数对齐，而不是里面的元素以这样的字节数对齐,里面的元素还是以4字节对齐的方式来对齐
#include <stdio.h>

//#pragma pack(2)			//#pragma pack(n)这样在这个区间之内就可以设置多少字节对齐了

struct struct1
{				//1字节分析			4字节分析
	char a;		//1					4
	int b;		//4					4
	char c;		//1					4
};


//3.struct1采用1字节对齐的话，那么最终结果是8
//2.加上了字节对齐之后，这里的结果是14，因为struct1采用的是4字节对齐，所以是4
//1.最终的结果是12，所以struct struct1类型是封装起来的，编译器看到它就是一个占12字节的
struct struct2
{
	char a;				//4			1		1
	struct struct1 b;	//12		12		6
	char c;				//4			1		1
}__attribute__((aligned(1)));			//__attribute__((packed));//packed的作用是取消对齐访问

//#pragma pack(2)

struct struct3
{
	//2
	short a;
};

struct struct4
{
	//10
	char a;
	struct struct3 b;
	char c;
	short e;
	char d;
};

struct struct5
{
	char c;
	short e;
	int f;
	char d;
	short g;
	char h;
};

struct struct6
{
	char c;
	double e;
	char d;
};

struct str
{
	char a[5];		//0
	short e;
	int b;			//8
	double c;		//12
	float d;		//20
}s1;

int main (void)
{
	printf("sizeof(struct struct2) = %d.\n", sizeof(struct struct2));
	printf("sizeof(struct struct4) = %d.\n", sizeof(struct struct4));
	printf("sizeof(struct struct3) = %d.\n", sizeof(struct struct3));
	printf("sizeof(struct struct5) = %d.\n", sizeof(struct struct5));
	printf("sizeof(struct struct6) = %d.\n", sizeof(struct struct6));
	
	/*
	s1.a[0] = 'a';
	s1.a[1] = 'b';
	s1.a[2] = 'c';
	s1.e = 2;
	s1.b = 10;
	s1.c = 3.14;
	s1.d = 2.22;
	
	short *p2 = (short *)((int)&s1 + 6);  //由此我们就知道了,char和short之间隔了一个字节,填充了
	char *p = (char *)(&s1);			 //可以用指针的形式来访问结构体的变量的
	int *p1 = (int *)((int)&s1 + 8);	//struct使用的是内存对齐，所以后面不是1而是4
	
	printf("a = %c.\n", *p);
	printf("a = %c.\n", *(p+1));
	printf("b = %d.\n", *p1);
	printf("e = %d.\n", *p2);
	*/
	
	return 0;
}































