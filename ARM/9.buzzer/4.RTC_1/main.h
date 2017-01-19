#ifndef __MAIN_H__
#define __MAIN_H__

// main.h����������Ÿ�������Ĳ���������������

// key.c
void key_init_interrupt(void);
void isr_eint2(void);
void isr_eint3(void);
void isr_eint16171819(void);
void key_init(void);
void key_polling(void);

// led.c
void led_blink(void);
void led1(void);
void led2(void);
void led3(void);
void led_off(void);


// uart.c
void uart_init(void);

//wdt.c
void isr_wdt(void);
void wdt_init_interrupt(void);

//rtc.c
struct rtc_time
{
	unsigned int year;
	unsigned int month;
	unsigned int day;				//��������
	unsigned int hour;
	unsigned int minute;
	unsigned int second;
	unsigned int dayweek;				//�������ڼ�
};

void rtc_set_time(const struct rtc_time *p);
void rtc_get_time(struct rtc_time *p);
static unsigned int num_to_BCD(unsigned int num);
static unsigned int BCD_to_num(unsigned int num);












#endif



















