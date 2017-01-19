#ifndef __MAIN_H__
#define __MAIN_H__


//key.c_
void key_inter_init(void);
void isr_eint2(void);
void isr_eint3(void);
void isr_eint16171819(void);
void key_init(void);
void key_polling(void);


//uart.c
void uart_init(void);

//led.c
void led_blink(void);
void led1(void);
void led2(void);
void led3(void);
void led_off(void);








#endif