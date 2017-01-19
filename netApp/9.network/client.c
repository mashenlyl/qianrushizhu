#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>          /* See NOTES */
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#define SERPORT 	6500
#define SERIPADDR 	"192.168.171.128"
#define BACKLOG 	100

int main(void)
{
	int socketfd = -1, ret = -1;
	struct sockaddr_in seraddr;
	char buf[50] = "hello world.";
	
	// 第一步：用socket来打开文件
	socketfd = socket(AF_INET, SOCK_STREAM, 0);
	if(socketfd < 0)
	{
		perror("socket");
		return -1;
	}
	printf("socketfd = %d\n", socketfd);
	
	// 第二步，connect连接
	seraddr.sin_family = AF_INET;
	seraddr.sin_port = SERPORT;
	seraddr.sin_addr.s_addr =  inet_addr(SERIPADDR);
	ret = connect(socketfd, (const struct sockaddr *)&seraddr, sizeof(seraddr));
	if(ret != 0)
	{
		perror("connect");
		return -1;
	}
	printf("连接成功\n");
	
	/*
	// 第五步，send，发送数据
	ret = send(socketfd, buf, strlen(buf), 0);
	printf("成功发送了%d字节\n", ret);
	*/
	
	/*
	// 循环输入
	while(1)
	{
		memset(buf, 0, sizeof(buf));
		scanf("%s", buf);
		ret = send(socketfd, buf, strlen(buf), 0);
		printf("成功发送了%d字节\n", ret);
	}
	*/
	
	ret = recv(socketfd, buf, sizeof(buf), 0);
	printf("成功读取了%d字节\n", ret);
	printf("发送的内容：[%s]\n", buf);
	
	return 0;
}






