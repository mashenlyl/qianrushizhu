#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>


int main(void)
{
	DIR * dirp = NULL;
	struct dirent * dit = NULL;
	
	dirp = opendir("../3");
	dit = readdir(dirp);
	
	while(dit != NULL)
	{
		printf("dit = %p\n", dit);
		printf("name = [%s]\n", dit->d_name);
		dit = readdir(dirp);
	}
	
	return 0;
}

























