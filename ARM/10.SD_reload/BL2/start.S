/*
 * 文件名：	led.s	
 * 作者：	朱老师
 * 描述：	演示重定位（在SRAM内部重定位）
 */

#define WTCON		0xE2700000

#define SVC_STACK	0xd0037d80

.global _start					// 把_start链接属性改为外部，这样其他文件就可以看见_start了
_start:

	ldr pc, =led_blink				// ldr指令实现长跳转
	
	
	// 从这里之后就可以开始调用C程序了
	//bl led_blink					// bl指令实现短跳转
	
// 汇编最后的这个死循环不能丢
	b .
	

	
	
	

	
	
	
	
	
	
	
	
	
