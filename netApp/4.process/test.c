#include <stdio.h>

void prit(char * num[])
{
	int i = 0;
	
	for(i=0; num!=NULL; num++, i++)
	{
		printf("num[%d] = %s\n", i, num[i]);
	}
}

int main(void)
{
	int i=0;
	char num[][10] = {"hello", "world", "OK", "heehhe", "tianay"};
	prit(num);
	
	
	return 0;
}