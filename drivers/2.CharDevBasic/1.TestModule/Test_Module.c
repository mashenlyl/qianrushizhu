#include <linux/kernel.h>		// printk
#include <linux/init.h>			// __exit __init
#include <linux/module.h>      //module_init module_exit

// insmod�İ�װģ��ĺ���
static int __init test_init(void)
{
	printk(KERN_INFO "test_init install\n");
	return 0;
}

// rmmod��ж��ģ��ĺ���
static void __exit test_exit(void)
{
	printk(KERN_INFO "test_exit exit\n");
}

// �Ѱ�װģ��ĺ�����insmod���������
// ��ж��ģ��ĺ�����rmmod���������
module_init(test_init);
module_exit(test_exit);

// ����ĺ���modinfo�����ʱ����ʾ����Ϣ
// ���֤��Ϣ
MODULE_LICENSE("GPL");
// ����
MODULE_AUTHOR("lyl");
// ģ��Ľ���
MODULE_DESCRIPTION("lyl test module");




