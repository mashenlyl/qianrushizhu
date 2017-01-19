#include "main.h"

#define 	RTC_BASE	(0xE2800030)

//注意最后面加上括号，不加括号就出错了
#define		rINTP		(*(volatile unsigned long *)(RTC_BASE + 0x00))
#define		rRTCCON		(*(volatile unsigned long *)(RTC_BASE + 0x10))
#define		rRTCALM		(*(volatile unsigned long *)(RTC_BASE + 0x20))
#define		rALMSEC		(*(volatile unsigned long *)(RTC_BASE + 0x24))
#define		rALMMIN		(*(volatile unsigned long *)(RTC_BASE + 0x28))
#define		rALMHOUR	(*(volatile unsigned long *)(RTC_BASE + 0x2C))
#define		rALMDAY		(*(volatile unsigned long *)(RTC_BASE + 0x30))
#define		rALMMON		(*(volatile unsigned long *)(RTC_BASE + 0x34))
#define		rALMYEAR	(*(volatile unsigned long *)(RTC_BASE + 0x38))
#define		rBCDSEC		(*(volatile unsigned long *)(RTC_BASE + 0x40))
#define		rBCDMIN		(*(volatile unsigned long *)(RTC_BASE + 0x44))
#define		rBCDHOUR	(*(volatile unsigned long *)(RTC_BASE + 0x48))
#define		rBCDDAYWEEK	(*(volatile unsigned long *)(RTC_BASE + 0x4C))
#define		rBCDDAY		(*(volatile unsigned long *)(RTC_BASE + 0x50))
#define		rBCDMON		(*(volatile unsigned long *)(RTC_BASE + 0x54))
#define		rBCDYEAR	(*(volatile unsigned long *)(RTC_BASE + 0x58))
#define		rCURTICCNT	(*(volatile unsigned long *)(RTC_BASE + 0x60))


//写时间的函数
void rtc_set_time(const struct rtc_time *p)
{
	//RTC一上电就可以工作了，不需要初始化，只需要打开就可以了
	//第一步：打开开关
	rRTCCON |= (1<<0);
	
	//注意这个年是按照2000年为基准的
	rBCDYEAR 	= num_to_BCD(p->year - 2000);
	rBCDMON 	= num_to_BCD(p->month);
	rBCDDAY 	= num_to_BCD(p->day);
	rBCDHOUR 	= num_to_BCD(p->hour);
	rBCDMIN 	= num_to_BCD(p->minute);
	rBCDSEC 	= num_to_BCD(p->second);
	rBCDDAYWEEK = num_to_BCD(p->dayweek);
	
	//最后：关闭开关
	rRTCCON &= ~(1<<0);
}

//读时间的函数
void rtc_get_time(struct rtc_time *p)
{
	//第一步：打开开关
	rRTCCON |= (1<<0);
	
	p->year 	= BCD_to_num(rBCDYEAR) + 2000;
	p->month 	= BCD_to_num(rBCDMON);
	p->day 		= BCD_to_num(rBCDDAY);
	p->hour 	= BCD_to_num(rBCDHOUR);
	p->minute 	= BCD_to_num(rBCDMIN);
	p->second 	= BCD_to_num(rBCDSEC);
	p->dayweek 	= BCD_to_num(rBCDDAYWEEK);
	
	//最后：关闭开关
	rRTCCON &= ~(1<<0);
}


//十进制转换BCD码的函数
static unsigned int num_to_BCD(unsigned int num)
{
	//只需要两步.第一步是：把它拆成两个数字.第二步：把两个数字组合起来
		
	return (((num/10)<<4) | (num%10));
}

//BCD码转换为十进制的函数
static unsigned int BCD_to_num(unsigned int bcd)
{
	//也是需要两步。第一步是：得到两个数字。第二步是：把数字组合成十进制的
	
	return ((((bcd&0xf0)>>4)*10)+(bcd&0x0f));
}





























