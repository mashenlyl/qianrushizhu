#include <stdio.h>
#include "a.h"					//ͷ�ļ��������൱����ԭ��չ����˵���������Լ�д��

int main (void)
{
	int a, b, c, d;
	
	a = 10;
	b = 20;
	
	c = add(a,b);
	d = sub(a,b);
	
	printf("c = %d.\n", c);
	printf("d = %d.\n", d);
	
	return 0;
}


















