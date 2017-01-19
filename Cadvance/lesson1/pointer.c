# include <stdio.h>
int main (void)
{
	int x, y;
	x = 5, y = 3;
	printf("x = %d, y = %d.\n", x, y); 
	swap(&x, &y); 
	printf("x = %d, y = %d.\n", x, y);
	
	return 0;
} 

int swap (int *p1, int *p2)
{
	int temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
} 
