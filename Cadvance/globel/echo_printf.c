#include <stdio.h>

int main (void)
{
	int ch;
	
	while((ch = getchar()) != EOF)		//ch != EOF ��ʱ�򣬾�ִ���������
	{
		putchar(ch);
	}
	
	return 0;
}