#include <stdio.h>

#define DEBUG_S3C_MEM


//���fmt�Ķ����ǣ�const char *fmt,���Ե�һ��Ҫ���ַ�����
#ifdef DEBUG_S3C_MEM
#define DEBUG(fmt, args...) 	printf(fmt, ##args)
#else
#define DEBUG(fmt, args...) 	do {} while (0)
#endif

int main (void)
{
	DEBUG("This is DEBUG\n");
	
	return 0;
}