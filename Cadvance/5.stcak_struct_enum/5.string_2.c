#include <stdio.h>
#include <string.h>

int Mystrlen(char *p)
{
	int cnt = 0;
	while(*p++ != '\0')		//*p++，++在后面，p先和*结合，然后++，++的优先级是很高的
	{
		cnt++;
	}
	return cnt;
	/*
	int i = 0;
	while (*(p+i) != '\0')
	{
		i++;
	}
	return i;
	*/
}

int main (void)
{
	char s[12] = "linux";
	char *p3 = "linux";
	printf("sizeof(s) = %d.\n", sizeof(s));		//12
	printf("strlen(s) = %d.\n", strlen(s));		//5
	printf("Mystrlen(s) = %d.\n", Mystrlen(s));	
	
	return 0;
}



































