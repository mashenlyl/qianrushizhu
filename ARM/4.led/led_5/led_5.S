/*
 *
 *	名字：led_5.S
 *	作用：写延迟函数，使得led灯闪烁
 *
 */
 
#define GPJ0CON  0xE0200240			
#define GPJ0DAT  0xE0200244

.global _start				//定义全局变量了，就是可以起到在外部链接的作用
 _start:						
	ldr r0, =GPJ0CON			
	ldr r1, =0x11111111
	str r1, [r0]					
	
	//全部亮
	ldr r0, =0x0					
	ldr r1, =GPJ0DAT						
	str r0, [r1]
	
	//延迟
	bl delay
	
	//全部灭
	ldr r0, =0xff
	ldr r1, =GPJ0DAT
	str r0, [r1]
	
	//延迟
	bl delay
	
	//全部亮
	ldr r0, =0x0					
	ldr r1, =GPJ0DAT						
	str r0, [r1]
	
	b .					

 
delay:
	ldr r2, =9000000
	ldr r3, =0x0
	
delay_loop:
	sub r2, r2, #1						//这里就是等价于：sub r2, #1，其实就是r2 = r2 - 1;  
	cmp r2, r3					
	bne delay_loop
	mov pc, lr					
	
 
 /*
 总结：
 1. bne用法：
 bne指令： 非零则跳转

个人总结：tst 和bne连用: 先是用cmp进行那个比较，然后将比较的结果与0比较，如果不为0，则跳到bne紧跟着的标记（如bne sleep，则跳到sleep处）。就是说不相等就跳转。

2.cmp的用法：
cmp是比较指令,cmp的功能相当于减法指令。它不保存结果，只是影响相应的标志位。ZF (Zero Flag):零标志位。
它记录相关指令执行后，其结果是否为0
其他的指令通过识别这些被影响的标志位来得知比较结果。

cmp指令格式:   cmp   操作对象1, 操作对象2

计算 操作对象1 - 操作对象2 但不保存结果，只是根据结果修改相应的标志位。
也就是说它把标志位修改成了1了。因为不相等就跳转，并且不为零就跳转

3.b指令和bl指令的区别：
B或BL指令引起处理器转移到“子程序名”处开始执行。两者的不同之处在于BL指令在转移到子程序执行之前，
将其下一条指令的地址拷贝到R14（LR,链接寄存器）。由于BL指令保存了下条指令的地址，
因此使用指令“MOV PC ,LR”即可实现子程序的返回。而B指令则无法实现子程序的返回，只能实现单纯的跳转。
用户在编程的时候，可根据具体应用选用合适的子程序调用语句。

b delay :就可以跳转到delay下面的那个程序那里执行了，和bl delay也可以

 */
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 