#include "stdio.h"
#include "inter.h"
#include "main.h"

#define KEY_EINT2		NUM_EINT2		// left
#define KEY_EINT3		NUM_EINT3		// down
#define KEY_EINT16_19	NUM_EINT16_31	// 其余4个共用的

void uart_init(void);


int main (void)
{
	uart_init();
	//key_init();
	//key_polling();
	
	
	//先初始化中断
	system_init_exception();
	
	//初始化外部中断
	key_inter_init();
	
	printf("------------------key interrupt--------------");
	
	//然后绑定isr的值
	intc_setvectaddr(KEY_EINT2,isr_eint2);
	intc_setvectaddr(KEY_EINT3,isr_eint3);
	intc_setvectaddr(KEY_EINT16_19,isr_eint16171819);
	
	//之后就是使能中断
	intc_enable(KEY_EINT2);
	intc_enable(KEY_EINT3);
	intc_enable(KEY_EINT16_19);
	
	// 在这里加个心跳
	return 0;
}


































