#include "shell.h"

void putchar(char c)
{
	//因为windows是回车换行是：“\r\n”，而linux中的是‘\n’，所以输出的时候要加上\r才可以
	if(c=='\n')
		uart_putc('\r');
		
	uart_putc(c);
}

void puts(const char *str)
{
	while(*str != '\0')
	{
		putchar(*str++);
	}
}

char getchar(void)
{
	char c;
	c = uart_getc();
	
	if(c == '\r')
		c = '\n';
	return c;
}

// 这就相当于scanf("%s", &str)这里的str了
char* gets(char *str)
{
	char *str1 = str;
	char ch;
	
	//以换行符为输完一行的结束标志
	while((ch = getchar()) != '\n')
	{
		//假设输入的是Backspace这个按键的话
		if(ch == '\b')
		{
			if(str>str1)
			{
				//你按下这个键，我就让你看见它按回去了,
				putchar('\b');
				//然后用空字符来覆盖已经输出的字符，表示删除了字符
				putchar(' ');
				//然后再退回来指向前一格
				putchar('\b');
				
				//指针退回来指向前一格
				str--;
			}
		}
		else
		{
			putchar(ch);
			*str++ = ch;
		}
	}
	//遇到换行符结束，添加'\0'作为字符串结束标志
	*str = '\0';
	putchar('\n');
}




























