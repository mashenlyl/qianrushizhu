#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>


int main(void)
{
	int ret = 0, result = 0;
	struct stat buf;
	
	memset(&buf, 0, sizeof(buf));
	
	ret = 10;
	ret = access("1.txt", F_OK);
	
	if(0 == ret)
	{
		printf("存在这个文件\n");
	}
	
	ret = 10;
	ret = chmod("1.txt", S_IRUSR);
	
	if(0 == ret)
	{
		printf("修改权限成功\n");
	}
	
	ret = 10;
	ret = stat("1.txt", &buf);
	
	if(ret == 0)
	{
		result = (S_IRWXU & buf.st_mode);
		printf("权限：%o.\n", result);
	}
	
	ret = 10;
	ret = chown("1.txt", -1, 0);			// 输入0的话就是修改为当前执行该程序的用户，输入-1就不修改
	if(ret == 0)
	{
		printf("修改用户成功\n");
	}
	
	
/*
	result = (S_IRWXU & buf.st_mode);
	printf("权限：%d.\n", result);			//得到的结果是384->八进制是600->root用户的权限rw
*/
	
	return 0;
}


