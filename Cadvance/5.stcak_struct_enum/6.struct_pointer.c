//�ܽ᣺#pragma pack(n)�ǽṹ����ÿ��Ԫ�ض����������ֽ��������룬����n����4֮��Ͳ���ʲô������
//__attribute__((packed))������1�ֽڶ������ʽ
//__attribute__((aligned(1)))�����������1,2,4,8,16�������ֽ������룬�����������Ԫ�����������ֽ�������,�����Ԫ�ػ�����4�ֽڶ���ķ�ʽ������
#include <stdio.h>

//#pragma pack(2)			//#pragma pack(n)�������������֮�ھͿ������ö����ֽڶ�����

struct struct1
{				//1�ֽڷ���			4�ֽڷ���
	char a;		//1					4
	int b;		//4					4
	char c;		//1					4
};


//3.struct1����1�ֽڶ���Ļ�����ô���ս����8
//2.�������ֽڶ���֮������Ľ����14����Ϊstruct1���õ���4�ֽڶ��룬������4
//1.���յĽ����12������struct struct1�����Ƿ�װ�����ģ�����������������һ��ռ12�ֽڵ�
struct struct2
{
	char a;				//4			1		1
	struct struct1 b;	//12		12		6
	char c;				//4			1		1
}__attribute__((aligned(1)));			//__attribute__((packed));//packed��������ȡ���������

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
	
	short *p2 = (short *)((int)&s1 + 6);  //�ɴ����Ǿ�֪����,char��short֮�����һ���ֽ�,�����
	char *p = (char *)(&s1);			 //������ָ�����ʽ�����ʽṹ��ı�����
	int *p1 = (int *)((int)&s1 + 8);	//structʹ�õ����ڴ���룬���Ժ��治��1����4
	
	printf("a = %c.\n", *p);
	printf("a = %c.\n", *(p+1));
	printf("b = %d.\n", *p1);
	printf("e = %d.\n", *p2);
	*/
	
	return 0;
}































