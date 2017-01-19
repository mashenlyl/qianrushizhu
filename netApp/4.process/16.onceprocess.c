#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(void)
{
	int fd = -1, i = 0;
	fd = open("/var/lyl_process_test", O_RDONLY | O_CREAT | O_TRUNC | O_EXCL);
	if(fd < 0)
	{
		printf("打开程序失败\n");
		return -1;
	}
	printf("打开程序成功\n");
	for(i=0; i<15; i++)
	{
		sleep(1);
		printf("i = %d\n", i);
	}
	
	
	close(fd);
	remove("/var/lyl_process_test");

	return 0;
}
