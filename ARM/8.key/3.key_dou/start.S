/*
 *
 *	名字：start.s
 *	作用：开或关icache
 *
 */

#define WTCON    0xE2700000
#define SVC_SP   0xD0037D80

.global _start				
 _start:
	
	//关看门狗,操作看门狗的那个寄存器就是WTCON，那个观看门狗的那个功能就是第五位，0表示关，1表示的是开
	ldr r0, =WTCON
	ldr r1, =0x0
	str r1, [r0]
	
	//这里设置栈,这样就设置好了栈了，之后就可以用c语言来编程了
	ldr sp, =SVC_SP
	
	//开icache
	mrc p15,0,r0,c1,c0,0;			// 读出cp15的c1到r0中
	bic r0, r0, #(1<<12)			// bit12 置0  关icache
	orr r0, r0, #(1<<12)			// bit12 置1  开icache
	mcr p15,0,r0,c1,c0,0;			//这里是写入的意思
	
	//设置模式，下面的都是功能代码
	bl key_init
	
	bl key_polling
	
	//注意最后还是要加上一个死循环的呀，防止程序出错的时候跑飞了
	b .
 
 
/*
总结：
icache就是高级缓存的意思
因为速度上：cpu > 寄存器 > icache > ddr > 硬盘
储存大小上：cpu < 寄存器 < icache < ddr < 硬盘
为了价钱和性能的平衡，就加入多阶缓存的计算机。
icache的作用就是：事先把cpu可能要用到的指令读出来，放到它那里。然后cpu要哪条就给它，这样就不用再去内存中读取了

关掉那个icache，led的闪烁变慢了很多，所以说开icache可以提高运行速度
在irom的bl0中是默认打开icache的。
*/
 
 
 
 
 
 
 
 
 