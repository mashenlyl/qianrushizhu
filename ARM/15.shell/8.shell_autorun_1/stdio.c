#include "shell.h"

void putchar(char c)
{
	//��Ϊwindows�ǻس������ǣ���\r\n������linux�е��ǡ�\n�������������ʱ��Ҫ����\r�ſ���
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

// ����൱��scanf("%s", &str)�����str��
char* gets(char *str)
{
	char *str1 = str;
	char ch;
	
	//�Ի��з�Ϊ����һ�еĽ�����־
	while((ch = getchar()) != '\n')
	{
		//�����������Backspace��������Ļ�
		if(ch == '\b')
		{
			if(str>str1)
			{
				//�㰴����������Ҿ����㿴��������ȥ��,
				putchar('\b');
				//Ȼ���ÿ��ַ��������Ѿ�������ַ�����ʾɾ�����ַ�
				putchar(' ');
				//Ȼ�����˻���ָ��ǰһ��
				putchar('\b');
				
				//ָ���˻���ָ��ǰһ��
				str--;
			}
		}
		else
		{
			putchar(ch);
			*str++ = ch;
		}
	}
	//�������з����������'\0'��Ϊ�ַ���������־
	*str = '\0';
	putchar('\n');
}




























