#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	FILE* fd = NULL;
	int count = -1;
	char buf[20] = "I LOVE LINUX!";
	
	// ���ļ���ʹ��fopen�����ļ���w+�ǿɶ���д��û���ļ��ʹ����ļ������ļ�������ļ���
	fd = fopen("1.txt", "w+");
	
	// д�ļ�
	count = fwrite(buf, sizeof(char), strlen(buf), fd);
	if(-1 == count)
	{
		perror("fwrite");
		_exit(-1);
	}
	else
	{
		printf("count = %d.\n", count);
	}
	
	// �ر��ļ�
	fclose(fd);
	
	return 0;
}


