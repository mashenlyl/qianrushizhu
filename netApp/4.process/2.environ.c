#include <stdio.h>
#include <stdlib.h>


int main(void)
{
#if 0
	// ע�⣺��Ҫ���������������ⲿ�ı�������Ȼ�ͱ��δ����ˣ�
	extern char ** environ;
	int i = 0;
	
	while(NULL != environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
#endif

	printf("%s\n", getenv("PATH"));
	return 0;
}
