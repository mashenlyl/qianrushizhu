/*
 * 文件名：	led.s	
 * 作者：	朱老师
 * 描述：	演示重定位（在SRAM内部重定位）
 */

#define WTCON		0xE2700000

#define SVC_STACK	0xd0037d80

.global _start					// 把_start链接属性改为外部，这样其他文件就可以看见_start了
_start:
	//第0步：置锁软开关
	ldr r0, =0xE010E81C
	ldr r1, =0x301
	str r1, [r0]
	
	// 第1步：关看门狗（向WTCON的bit5写入0即可）
	ldr r0, =WTCON
	ldr r1, =0x0
	str r1, [r0]
	
	// 第2步：设置SVC栈
	ldr sp, =SVC_STACK
	
	// 第3步：开/关icache
	mrc p15,0,r0,c1,c0,0;			// 读出cp15的c1到r0中
	//bic r0, r0, #(1<<12)			// bit12 置0  关icache
	orr r0, r0, #(1<<12)			// bit12 置1  开icache
	mcr p15,0,r0,c1,c0,0;

	// 第4步：初始化ddr
	bl sdram_asm_init
	
	// 第5步：重定位
	bl copy_bl2_to_ddr
	
	
//run_on_dram:	
	// 长跳转到led_blink开始第二阶段
	//ldr pc, =led_blink				// ldr指令实现长跳转
	
	
	// 从这里之后就可以开始调用C程序了
	//bl led_blink					// bl指令实现短跳转
	
// 汇编最后的这个死循环不能丢
	b .
	

	
	
	

	
	
	
	
	
	
	
	
	
