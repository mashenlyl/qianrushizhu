#include "shell.h"

void memset(char *s, int val, int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		*s++ = val;
	}
}

int strcmp(const char *s1, const char *s2)
{
	unsigned char c1, c2;
	
	while(1)
	{
		c1 = *s1++;
		c2 = *s2++;
		if(c1 != c2)
			return c1 < c2 ? -1 : 1;
		if(!c1)
			break;
	}
	return 0;
}

void strcpy(char *dest, const char *src)
{
	while(*src != '\0')
	{
		*dest++ = *src++;
	}
	*dest = '\0';
}

void cmd_division(char cmd[][CMD_LENGTH_PART], char *str)
{
	int m=0, n=0;
	
	while(*str != '\0')
	{
		if(*str != ' ')
		{
			cmd[m][n] = *str;
			n++;
		}
		else
		{
			cmd[m][n] = '\0';
			m++;
			n = 0;
		}
		str++;
	}
	cmd[m][n] = '\0';
}


























