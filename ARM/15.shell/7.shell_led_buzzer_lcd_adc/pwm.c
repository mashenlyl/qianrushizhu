
//定义好相应的寄存器
#define		GPD0CON		(0xE02000A0)
#define 	TCFG0		(0xE2500000)
#define		TCFG1		(0xE2500004)
#define		CON			(0xE2500008)
#define		TCNTB2		(0xE2500024)
#define		TCMPB2		(0xE2500028)

#define 	rGPD0CON	(*(volatile unsigned int *)GPD0CON)
#define 	rTCFG0		(*(volatile unsigned int *)TCFG0)
#define 	rTCFG1		(*(volatile unsigned int *)TCFG1)
#define 	rCON		(*(volatile unsigned int *)CON)
#define 	rTCNTB2		(*(volatile unsigned int *)TCNTB2)
#define 	rTCMPB2		(*(volatile unsigned int *)TCMPB2)

void pwm_init(void)
{
	//其实硬件上帮我们做了很多工作了，然后我们就不用使用中断就可以输出PWM波形了
	// 初始化GPD0CON（8~11）,选择TOUT模式，首先清零，然后写2
	rGPD0CON &= ~(0xf<<8);
	rGPD0CON |= (2<<8);
	
	// 设置寄存器TCFG0(8~15)，设置rescaler 1为65，得到了就是1MHz
	rTCFG0 &= ~(0xff<<8);
	rTCFG0 |= (65<<8);
	
	// 设置寄存器TCFG1(8~11),设置MUX2，选择1/2（0001），得到500kHz（0.2us）
	rTCFG1 &= ~(0xf<<8);
	rTCFG1 |= (1<<8);
	
	// 设置寄存器CON time2段的
	//自动重载
	rCON |= (1<<15);
	
	//设置寄存器TCNTB2，我们设置频率是2kHz（0.5ms）的，占比率是50%，所以得到值为500
	rTCNTB2 = 500;
	rTCMPB2 = 250;
	
	// 手动刷入到TCNT这里，之后又关闭手动刷新
	rCON |= (1<<13);
	rCON &= ~(1<<13);
	
	//最后一步就是开启定时器
	rCON |= (1<<12);
	
}

void buzzer_off(void)
{
	rGPD0CON &= ~(0xf<<8);
	rGPD0CON |= (0<<8);
}

void buzzer_on(void)
{
	rGPD0CON &= ~(0xf<<8);
	rGPD0CON |= (2<<8);
}


























