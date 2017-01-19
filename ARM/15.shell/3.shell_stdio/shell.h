#ifndef __SHELL_H__
#define __SHELL_H__

//串口输入/输出函数
void uart_putc(char c);
char uart_getc(void);

//标准输入输出函数
void putchar(char c);
void puts(const char *str);
char getchar(void);
char* gets(char *str);









#endif