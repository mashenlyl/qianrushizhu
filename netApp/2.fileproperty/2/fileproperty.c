#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>


int main(void)
{
	int ret;
	struct stat buf;
	
	memset(&buf, 0, sizeof(buf));
	
	ret = stat("1.txt", &buf);
	
	if(ret == -1)
	{
		perror("stat");
	}
	
	printf("st_size = %d.\n", buf.st_size);
	printf("st_blocks = %d.\n", buf.st_blocks);
	printf("Last status change:       %s", ctime(&buf.st_ctime));
    printf("Last file access:         %s", ctime(&buf.st_atime));
    printf("Last file modification:   %s", ctime(&buf.st_mtime));
	
	
	return 0;
}


