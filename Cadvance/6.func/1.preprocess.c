
#include <stdio.h>

typedef char * PCHAR;

//#define pchar ��char *��		�������ž��൱��ǿ������ת���ˣ�����Ҳ���հ���ȥ�ģ���������Ҫע���Ƿ�Ҫ��������
#define pchar char *

int main (void)
{
	char a = 3, b = 4, c = 5;
	PCHAR p1, p2;
	pchar p3;
	
	p1 = &a;
	p2 = &b;
	
	return 0;
}






























