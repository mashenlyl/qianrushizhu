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
	
	//重定位
	//adr是短跳转，只是在代码段处进行跳转，它用的是减法，得到的是当前运行环境的地址
	//ldr用的是长跳转，运用的是间接访问，在一个寄存器上放着一个内存地址，然后加载，就可以得到链接地址了
	//链接地址也可以在link.lds文件上看到的
	adr r0, _start					//把当前的运行地址给r0
	ldr r1, =_start					//把链接地址给r1
	ldr r2, =bss_start				//把bss段的链接地址给r2，这个bss段的地址可以在link.lds文件上看到的
	cmp r0, r1						//比较他们是不是一样		
	beq clean_bss					//一样就直接跳转到bss清零段
	
	//进行搬运
copy_loop:
	ldr r3, [r0], #4				//不一样就进行下面的复制
	str r3, [r1], #4				//很明显复制是一句句复制的
	cmp r1, r2						//最后那里是一个循环来的，如果还没到尾部，就继续循环
	bne copy_loop
	
	//bss段进行清零
clean_bss:
	ldr r0, =bss_start				
	ldr r1, =bss_end
	cmp r0, r1
	beq run_on_dram
	mov r2, #0
clear_loop:
	str r2, [r0], #4
	cmp r1, r0
	bne clear_loop
	
	//进行长跳转
run_on_dram:
	ldr pc, =led_blink
	
	//设置模式，下面的都是功能代码
	//bl led_blink
	
	//注意最后还是要加上一个死循环的呀，防止程序出错的时候跑飞了
	b .
 

 
 
 
 
 
 
 
 