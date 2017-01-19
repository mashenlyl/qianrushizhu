#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


int main(void)
{
	struct in_addr inp;
	
	//inet_aton("192.168.1.44", &inp);
	inet_pton(AF_INET, "192.168.1.44", &inp);
	//printf("ip = %x\n", inp.s_addr);
	//printf("ip = %x\n", inp.s_addr);
	
	return 0;
}