#include <stdio.h>

//����Ǵ������ĺ꣬ÿ�����嶼����Ҫ�Ǹ���������
#define MAX(a,b)	(((a)>(b))?(a):(b))

//ֻ������������ǿ������ת��
#define SEC_PER_YEAR	(365*24*60*60UL)

#define DEBUG
#undef DEBUG		//���������DEBUG���Ͳ����������û�У��ǾͲ���Ҫ�������

int main (void)
{
	#ifdef DEBUG
	printf("DEBUG.\n");
	#else
	printf("NODEBUG.\n");
	#endif
	
	int a = 5, b = 10;
	unsigned int c = SEC_PER_YEAR;
	
	printf("MAX(A,B) = %d.\n", MAX(a,b));
	printf("c = %d.\n", c);
	
	
	return 0;
}




























