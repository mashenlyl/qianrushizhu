# include <stdio.h>

int main (void)
{
	int a = 23;
	
	if(a)					//除了0是假外，其他数都是真的
	{
		int b = 0;            //这里的b是局部变量，只能在if这里用，外面是不能用的
		printf("a = %d.\n", a);   	 //局部变量的作用域是代码块的作用域
		printf("b = %d.\n", b);		 //也就是两个大括号间的一大块代码，就是其的作用域
	}
	
	//printf("b = %d.\n", b);			//在这里用就是错了的
	
	return 0;		/* 新标准主函数的返回值这条语句可以省略 */
}	

				
/*如果返回0，则代表程序正常退出。返回其它数字的含义则由系统决定。
   通常，返回非零代表程序异常退出。这和linux中的执行命令是一样的。
   也就是说如果命令执行不成功的话，那么就会返回非零的值，根据那个值也是可以找出错误所在的。
   执行成功就返回0值。但是这里return 1；程序也是可以执行成功的，这就不明白了。
*/