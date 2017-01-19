/*
 *
 *	名字：led_6.S
 *	作用：实现流水灯的效果，流水灯也叫走马灯,走过来又走过去
 *
 */
 
#define GPJ0CON  0xE0200240			
#define GPJ0DAT  0xE0200244
#define GPD0CON  0xE02000A0
#define GPD0DAT  0xE02000A4
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
	
	//设置模式，下面的都是功能代码
	ldr r0, =GPJ0CON
	ldr r2, =GPD0CON
	ldr r3, =0x00000010
	ldr r1, =0x11111111
	str r1, [r0]
	str r3, [r2]
	
	//先熄灭第四个灯，因为一开始默认是0的,所以就要先把它熄灭掉，为什么下面的灯不用熄灭呢，那就是程序
	//执行的很快，你根本没发现它就执行下去了
	ldr r0, =GPD0DAT
	ldr r1, =0xf				//注意：这里是很容易把它写成0x1的，f才是全部都是1，就是四个1
	str r1, [r0]
	
flash:
	//点亮第一个
	ldr r0, =GPJ0DAT
	ldr r1, =(0<<3)|(1<<4)|(1<<5)
	str r1, [r0]
	
	//延迟
	bl delay
	
	//点亮第二个
	ldr r0, =GPJ0DAT
	ldr r1, =(1<<3)|(0<<4)|(1<<5)
	str r1, [r0]
	
	//延迟
	bl delay
	
	//点亮第三个
	ldr r0, =GPJ0DAT
	ldr r1, =(1<<3)|(1<<4)|(0<<5)
	str r1, [r0]
	
	//延迟
	bl delay
	
	//之前三个全部熄灭
	ldr r0, =GPJ0DAT
	ldr r1, =(1<<3)|(1<<4)|(1<<5)
	str r1, [r0]
	
	//点亮第四个
	ldr r0, =GPD0DAT
	ldr r1, =0<<1
	str r1, [r0]
	
	//延迟
	bl delay
	
	//熄灭第四个
	ldr r0, =GPD0DAT
	ldr r1, =1<<1
	str r1, [r0]
	
	//点亮第三个
	ldr r0, =GPJ0DAT
	ldr r1, =(1<<3)|(1<<4)|(0<<5)
	str r1, [r0]
	
	//延迟
	bl delay
	
	//点亮第二个
	ldr r0, =GPJ0DAT
	ldr r1, =(1<<3)|(0<<4)|(1<<5)
	str r1, [r0]
	
	//延迟
	bl delay
	
	//点亮第一个
	ldr r0, =GPJ0DAT
	ldr r1, =(0<<3)|(1<<4)|(1<<5)
	str r1, [r0]
	
	b flash						
					
delay:
	ldr r2, =9000000
	ldr r3, =0x0
	
delay_loop:
	sub r2, r2, #1						 
	cmp r2, r3					
	bne delay_loop
	mov pc, lr		


/*
总结：
1.为什么需要栈：因为不可能全部都用汇编语言来写程序，太麻烦了，所以只用汇编来为c
语言搭建环境，c语言运行的环境就需要栈，所以就要在这里设置栈。
2.如何设置栈呢：我们系统在复位的时候默认进入的是svc模式，所以我们只需要设置svc模式下的栈即可。也就是在irom那里也有个svc track的，所以我们只需要直接访问sp（r13）（它是用来存放栈的）就可以了
3.栈的模式有什么：满减栈，满增栈，空减栈，空增栈。
满：就是指针指向的地方就是满的，如果要进栈就要先指向下一个地方再进栈。
								出栈的时候直接出就可以了
								
空：就是指针指向的地方就是空的，进栈的时候直接进来就可以了。
								如果要出栈就要先指向下一个地方再出栈。
增：指向下一个内存的时候是增加的，也就是地址的地址是增加的
减：就是指向下一个地址的时候是减少的，也就是地址的大小是减少的
4.arm中的ATPCS（ARM-Thumb Procedure Call Standard 就是一个标准来的）中定义使用的模式是满减栈，所以我们的起始地址就是上面那个：0xD0037D80
5.汇编语言和c语言之间是可以相互调用的
就是：bl cfunction
6.根据的是cpu内部的37个寄存器的用法：根据这张表显示, r0~r3一般用来传递函数的参数，r4~r7则用来放置局部变量. 而r12~r15则可以有特别的用途.
*/

 
 
 
 
 
 
 
 
 