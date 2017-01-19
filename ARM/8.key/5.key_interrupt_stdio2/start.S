/*
 * 文件名：	led.s	
 * 作者：	朱老师
 * 描述：	演示汇编开关icache
 */

#define WTCON		0xE2700000

#define SVC_STACK	0xd0037d80
#define IRQ_STACK	0xD0037F80

.global _start					// 把_start链接属性改为外部，这样其他文件就可以看见_start了
.global IRQ_handle
_start:
	// 第1步：关看门狗（向WTCON的bit5写入0即可）
	ldr r0, =WTCON
	ldr r1, =0x0
	str r1, [r0]
	
	// 第2步：初始化时钟
	bl clock_init
	
	// 第3步：设置SVC栈
	ldr sp, =SVC_STACK
	
	// 第4步：开/关icache
	mrc p15,0,r0,c1,c0,0;			// 读出cp15的c1到r0中
	//bic r0, r0, #(1<<12)			// bit12 置0  关icache
	orr r0, r0, #(1<<12)			// bit12 置1  开icache
	mcr p15,0,r0,c1,c0,0;

	bl main  						//直接用main函数来调用函数，这样就不用在这里写跳转到其他函数了。
	
	// 从这里之后就可以开始调用C程序了
	//bl led_blink					// led_blink是C语言实现的一个函数
	
// 汇编最后的这个死循环不能丢
	b .
	
IRQ_handle:
	//设置IRQ STACK栈
	ldr sp, =IRQ_STACK
	//保存LR寄存器
	sub lr, lr, #4
	//保存r0~r12,lr到irq下面的栈上
	stmfd sp!, {r0-r12, lr}
	//在这里调用真正的isr（中断处理程序）来处理中断
	bl irq_handler
	//恢复现场，就是中断返回，把R0-R12,PC,CPSR一起恢复
	ldmfd sp!, {r0-r12, pc}^

	
	
	
	
	
	
	
	
	
