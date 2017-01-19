#include <linux/kernel.h>		// printk
#include <linux/init.h>			// __exit __init
#include <linux/module.h>      // module_init module_exit
#include <linux/fs.h>			// file_operations

#define	 NAME		"Test"

int major = -1;

// 定义file_operations结构体中的元素相对应的函数
int test_chrdev_open (struct inode *inode, struct file *file)
{
	printk(KERN_INFO "test_chrdev_open open\n");
	return 0;
}

int test_chrdev_close(struct inode *inode, struct file *file)
{
	printk(KERN_INFO "test_chrdev_close close\n");
	return 0;
}

// 定义一个file_operations类型的结构体变量，可以直接在内核源代码中copy出来
static const struct file_operations test_fops = {
	.owner		= THIS_MODULE,					// 这个是照搬的，不需要变动的
	
	.open		= test_chrdev_open,
	.release	= test_chrdev_close,
};

// insmod的安装模块的函数
static int __init test_init(void)
{
	// 注册驱动程序，使用函数register_chrdev()
	// 如果给major传0的话，内核就会自动分配主设备号，返回值是主设备号
	major = register_chrdev(0, NAME, &test_fops);
	if (major < 0)
	{
		// 使用errno（在errno_base.h），出错的时候会返回出错详情；
		return -EINVAL;
	}
				  			  
	printk(KERN_INFO "test_init install\n");
	return 0;
}

// rmmod的卸载模块的函数
static void __exit test_exit(void)
{
	// 卸载驱动程序
	unregister_chrdev(major, NAME);
	
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




