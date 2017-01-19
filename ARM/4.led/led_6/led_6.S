/*
 *
 *	名字：led_6.S
 *	作用：写延迟函数，并且写循环函数，使得led灯闪烁
 *
 */
 
#define GPJ0CON  0xE0200240			
#define GPJ0DAT  0xE0200244

.global _start				
 _start:						
	ldr r0, =GPJ0CON			
	ldr r1, =0x11111111
	str r1, [r0]					
	
flash:
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
								//这里就完成了循环了
	b flash						//这里的作用就是跳转到上面的flash，其实这里写着b _start也是一样的，不过就是
								//从头再来了，就是从_start那里执行了。上次那个b . 和b _start的作用结果一样，但是
								//途径是不一样的，b . 就是在原地跳那样，而b _start就是跳转到了上面去执行了
					
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
1.b 和 bne的区别
B 是最简单的分支。一旦遇到一个 B 指令，ARM 处理器将立即跳转到给定的地址，从那里继续执行。
BNE指令，是个条件跳转，即:是“不相等(或不为0)跳转指令”。如果不为0就跳转到后面指定的地址，继续执行

2.照着上面这么说，那么beq的作用就是如果相等就跳转，不相等就不跳转
*/	
	
 
 
 
 
 
 
 
 
 
 
 
 
 