#include <stdio.h>

int main (void)
{
	int c[2] = {0x11223344, 0x55667788};
	char *p2;
	int a = 10;
	int *p;
	float *p1;
	
	p2 = (char *)c;
	p = &a;
	p1 = (float *)p;
	
	printf("*p = %d.\n", *p);
	printf("*p1 = %f.\n", *p1);
	printf("*p2 = 0x%x.\n", *p2);
	printf("*p2+1 = 0x%x.\n", *(p2+1));
	printf("*p2+2 = 0x%x.\n", *(p2+2));
	
	return 0;
}
















