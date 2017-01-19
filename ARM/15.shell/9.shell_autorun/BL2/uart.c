//注意：这次试了串口通信不行啊，就是寄存器的地址写错了，复制粘贴的时候大意了，把GPA0的地址复制过去了
//导致了错误，不能输出a

#define	GPA0CON		0xE0200000
#define ULCON0 		0xE2900000
#define UCON0 		0xE2900004
#define UFCON0 		0xE2900008
#define UMCON0 		0xE290000C
#define UBRDIV0 	0xE2900028
#define UDIVSLOT0	0xE290002C
#define UTRSTAT0	0xE2900010
#define UTXH0		0xE2900020
#define URXH0		0xE2900024


#define rGPAOCON		(*(volatile unsigned int *)GPA0CON)
#define rULCON0			(*(volatile unsigned int *)ULCON0)
#define rUCON0			(*(volatile unsigned int *)UCON0)
#define rUFCON0			(*(volatile unsigned int *)UFCON0)
#define rUMCON0			(*(volatile unsigned int *)UMCON0)
#define rUBRDIV0		(*(volatile unsigned int *)UBRDIV0)
#define rUDIVSLOT0		(*(volatile unsigned int *)UDIVSLOT0)
#define rUTRSTAT0		(*(volatile unsigned int *)UTRSTAT0)
#define rUTXH0			(*(volatile unsigned int *)UTXH0)
#define rURXH0			(*(volatile unsigned int *)URXH0)



void uart_init(void)
{
	//第一步：首先就是设置GPA0，设置这里是为了打开端口，只有打开端口，信息才会发送出去嘛
	//写上左移还是比较好的，虽然这次只是第一位开始：0~7
	//位操作就是先把那几位清零，然后赋值就ok了
	rGPAOCON &= (~(0xff<<0));			//这里少了一个分号，导致了30行出了错误
	rGPAOCON |= 0x00000022;			//这里不可以写成这样:0b00100010bit[3:0] = 0b0010 bit[7:4] = 0b0010
	
	//第二步：设置关键的寄存器,这些都是在数据手册中看的，在笔记中有。
	//这里是初始化UART控制器
	rULCON0 = 0x3;
	rUCON0 = 0x5;
	rUFCON0 = 0;
	rUMCON0 = 0;
	
	//第三步：设置波特率，计算波特率
	//这里的那个频率可以取66.7MHz，也是可以取66MHz
	//DIV_VAL = (PCLK / (bps x 16)) ?1
	//DIV_VAL = (66000000 / (115200 x 16)) - 1			算出来是34，余数是0.80729
	//rUBRDIV0 = 34;
	//(num of 1's in UDIVSLOTn)/16 = 0.7			0.8 可以算出是12.8
	//rUDIVSLOT0 = 0xdfdd;
	//当是66700000时候，算出来就是35.1870			0.2算出来是3，之后在下面查表，就看到相应的值了
	//这样就初始化串口了
	rUBRDIV0 = 34;
	rUDIVSLOT0 = 0xdfdd;
	
}


//发送一个字节
void uart_putc(char c)
{
	//发送字符的时候，要注意CPU比发送缓存区的速度要快很多的，所以我们要看发送缓存区是否已经发送完数据了
	//之后再给数据它
	//我们这里0就是非空，1就是空了，所以要等1的时候才跳出循环，而要跳出循环需要是0的时候才可以，所以
	//加上了！
	while(!(rUTRSTAT0 & (1<<1)));			//！是逻辑运算符，如果是真（非0）就变为假（0）
	rUTXH0 = c;
	
}

int g_getc(void)
{
	if((rUTRSTAT0 & (1<<0)))
	{
		return 1;
	}
	else
		return 0;
}

//接收一个字节
char uart_getc(void)
{
	//只是接收一个字节
	while(!(rUTRSTAT0 & (1<<0)));
	
	return (rURXH0 & 0xff);		//接收寄存器中只有八位是有效的，其他的都是无效的，所以在这里位与清零
									
}

inline void putc(char c)
{
	uart_putc(c);
}

inline char getc(void)
{
	uart_getc();
}



























