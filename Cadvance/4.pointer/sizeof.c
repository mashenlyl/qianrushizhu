//sizeof�����þ��ǲ����ڱ�ϵͳ����������ռ���ֽ���
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
	//˵������ȼ���һ��ָ���������
	printf("sizeof(b) = %d.\n", sizeof(b));				//4
}
*/

int main (void)
{
	//���ǿ�����ָ������������
	int b[4] = {1, 2, 3, 4};
	func1(b, sizeof(b)/sizeof(b[0]));
	
	/*
	dpChar p1,  p2;			//char *p1, p2;
	tpChar p3,  p4;			//char *p3,char *p4;
	//char *p1,������ָ�������
	printf("sizeof(p1) = %d.\n", sizeof(p1));				//4
	printf("sizeof(p1) = %d.\n", sizeof(p2));				//1
	printf("sizeof(p1) = %d.\n", sizeof(p3));				//4
	printf("sizeof(p1) = %d.\n", sizeof(p4));				//4
*/
/*
	char b[10] = {1, 2, 3};
	func(b);					//�������ﴫ��ʵ���ϴ����Ǹ�ָ������
	*/
	
	/*
	int b[100];			//sizeof(b)
	
	printf("sizeof(b) = %d.\n", sizeof(b));					//400,4(int)x100
	*/
	
	/*
	int n=10; 				//sizeof(n)
	
	printf("sizeof(n) = %d.\n", sizeof(n));					//4
	printf("sizeof(int) = %d.\n", sizeof(int));				//4�����һ����
	*/
	
	/*
	char str[] = "hello";
	char *p=str;  			//sizeof(p)	sizeof(*p)	strlen(p)
	
	//�����sizeof��ʾ��char *���ݽṹռ���ڴ���ֽ�����ָ�����͵Ķ���ռ4���ֽڵ�
	printf("sizeof(p) = %d.\n", sizeof(p));				//4
	//*p��ʾ������Ԫ�أ�������str������壬����ָ�����������飬��+1������
	printf("sizeof(*p) = %d.\n", sizeof(*p));			//1
	printf("*p = %c.\n", *p);							//h
	//str��������������Ϊ��Ԫ�ص��׵�ַ�������pҲֻ�����ĵ�ַ���ɴ˿�֪strlen����ҲֻҪ���ĵ�ַ�Ϳ�����
	printf("strlen(p) = %d.\n", strlen(p));				//5
	*/
	
	/*
	//��һ��
	char str[] = "hello";  //sizeof(str)	sizeof(str[0])	strlen(str)
	
	printf("str[] = %d.\n", sizeof(str));					//6��Ϊ�ַ��������и������������Զ�1
	printf("str[0] = %d.\n", sizeof(str[0]));				//1
	printf("strlen(str) = %d.\n", strlen(str));			//5��������Զ�ȥ���Ǹ��������ġ�
	
	*/
	
	return 0;
}





















