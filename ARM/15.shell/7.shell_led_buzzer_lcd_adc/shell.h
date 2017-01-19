#ifndef __SHELL_H__
#define __SHELL_H__

//一些宏定义和全局变量
// 最大的命令的长度
#define MAX_LINE_LENGTH 			256
#define CMD_NUM_PART				5
#define CMD_LENGTH_PART				20

//定义了三个命令
#define led 						"led"
#define lcd 						"lcd"
#define pwm 						"buzzer"
#define adc							"adc"
#define CMD_NUM						4

char g_cmdset[CMD_NUM][MAX_LINE_LENGTH];



//串口输入/输出函数
void uart_putc(char c);
char uart_getc(void);

//标准输入输出函数
void putchar(char c);
void puts(const char *str);
char getchar(void);
char* gets(char *str);

//和解析命令有关的函数
void init_cmdset(void);
void cmd_parse(char *str);
void cmd_exec(void);
void uart_init(void);
void do_error(void);
void do_led(void);
void do_buzzer(void);
void do_adc(void);
void do_lcd(void);

//和字符串有关的函数
void strcpy(char *dest, const char *src);
int strcmp(const char *s1, const char *s2);
void memset(char *s, int val, int n);
void cmd_division(char cmd[][CMD_LENGTH_PART], char *str);

//这里是硬件操作相关函数
//第一：led
void led_blink(void);
void led_init(void);
void led_on(void);
void led_off(void);

//第二：lcd
void lcd_on(void);
void lcd_init(void);

//第三：buzzer
void buzzer_on(void);
void buzzer_off(void);
void pwm_init(void);

//第四：adc
void adc_init(void);
void adc_on(void);



#endif