//静态局部变量在第一次函数调用的时候初始化，下次调用的时候不初始化，而是直接用上次
//留下的值，和全局变量类似，只初始化一次，函数退出的时候，变量没有被杀死，生命周期很长
//全局变量和静态局部变量的不同就是作用域不同，这就是局部变量的原因
#include <stdio.h>

void func1(void);
void func_static(void);
void func(void);
void func2(void);
void func_register(void);

int g_a;

int main (void)
{
	g_a = 5;
	
	func1();				//func1()函数每次用完之后变量就会被消灭掉
	func1();				//下次要用的时候再重新创建，所以得到的结果就是全部是1
	func1();				//i 全部都是1
	
	func_static();			//a = 1
	func_static();			//a = 2
	func_static();			//a = 3
	
	func();					//p = 3
	func();
	func();
	
	func2();				//g_a = 3
	func2();
	func2();
	
	func_register();				//全部都是1
	func_register();
	func_register();
	
	return 0;
}

void func1(void)
{
	int i = 0;				//前面可以加auto,可以省略，这就是普通局部变量
	
	i++;
	
	printf("i = %d.\n", i);
}

void func_static(void)
{
	static int a = 0;		//这句话不执行了，并且保留了上次的值
	
	a++;
	
	printf("a = %d.\n", a);
}

void func(void)
{
	static int p = 0;
	
	p += 3;
	
	printf("p = %d.\n", p);
}

void func2(void)
{
	
	g_a += 3;
	
	printf("g_a = %d.\n", g_a);
}

void func_register(void)
{
	
	register int d = 0;				//运行速度最快的变量，把它放在寄存器中，
	                                //其他的变量一般在内存中
	d++;							//不能太多，数据类型有限制，不可以定义double的类型
									//一般要频繁使用同一个变量的时候才会使用register变量
	printf("d = %d.\n", d);
}
































