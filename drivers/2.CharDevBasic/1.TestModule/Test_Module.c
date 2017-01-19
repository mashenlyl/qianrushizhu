#include <linux/kernel.h>		// printk
#include <linux/init.h>			// __exit __init
#include <linux/module.h>      //module_init module_exit

// insmod的安装模块的函数
static int __init test_init(void)
{
	printk(KERN_INFO "test_init install\n");
	return 0;
}

// rmmod的卸载模块的函数
static void __exit test_exit(void)
{
	printk(KERN_INFO "test_exit exit\n");
}

// 把安装模块的函数和insmod命令绑定起来
// 把卸载模块的函数和rmmod命令绑定起来
module_init(test_init);
module_exit(test_exit);

// 下面的宏是modinfo命令的时候显示的信息
// 许可证信息
MODULE_LICENSE("GPL");
// 作者
MODULE_AUTHOR("lyl");
// 模块的介绍
MODULE_DESCRIPTION("lyl test module");




