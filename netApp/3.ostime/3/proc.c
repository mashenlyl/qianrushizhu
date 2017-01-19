#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main(void)
{
	int fd;
	char buf[512] = {0};
	fd = open("/proc/cmdline", O_RDONLY);
	
	read(fd, buf, sizeof(buf));
	printf("%s", buf);
	
	return 0;
}