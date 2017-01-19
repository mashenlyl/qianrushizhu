#include <stdio.h>

#define SEC_PER_YEAR (365 * 24 * 60 * 60)   

int  main (void)
{
	unsigned int i;
	i = 365 * 24 * 60 * 60;
	printf("sec = %u", i); 
	printf("sec = %u", SEC_PER_YEAR);
	 
	return 0;
} 
