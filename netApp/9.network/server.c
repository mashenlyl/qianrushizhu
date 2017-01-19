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
	int socketfd = -1, ret = -1, clifd = -1;
	struct sockaddr_in seraddr;
	struct sockaddr_in cliaddr;
	socklen_t addrlen = 0;
	char buf[50] = "hello world";
	
	// 第一步：用socket来打开文件
	socketfd = socket(AF_INET, SOCK_STREAM, 0);
	if(socketfd < 0)
	{
		perror("socket");
		return -1;
	}
	printf("socketfd = %d\n", socketfd);
	
	// 第二步，bind绑定ip和端口号
	seraddr.sin_family = AF_INET;
	seraddr.sin_port = SERPORT;
	seraddr.sin_addr.s_addr =  inet_addr(SERIPADDR);
	ret = bind(socketfd, (const struct sockaddr *)&seraddr, sizeof(seraddr));
	if(ret != 0)
	{
		perror("bind");
		return -1;
	}
	printf("绑定成功\n");
	
	// 第三步，listen监听
	ret = listen(socketfd, BACKLOG);
	if(ret != 0)
	{
		perror("listen");
		return -1;
	}
	printf("监听成功\n");
	
	// 第四步，accept，阻塞等待客户端接入，服务器这边只有clifd才可以读写，socketfd是不可以读写的
	clifd = accept(socketfd, (struct sockaddr *)&cliaddr, &addrlen);
	if(clifd < 0)
	{
		perror("accept");
		return -1;
	}
	printf("clifd = %d\n", clifd);
	
	/*
	// 第五步，revc，接收数据
	ret = recv(clifd, buf, sizeof(buf), 0);
	printf("成功读取了%d字节\n", ret);
	printf("发送的内容：[%s]\n", buf);
	*/
	
	/*
	memset(buf, 0, sizeof(buf));
	while(1)
	{
		ret = recv(clifd, buf, sizeof(buf), 0);
		printf("成功读取了%d字节\n", ret);
		printf("发送的内容：[%s]\n", buf);
		memset(buf, 0, sizeof(buf));
	}
	*/
	
	// 发送数据
	ret = send(clifd, buf, strlen(buf), 0);
	printf("成功发送了%d字节\n", ret);
	
	return 0;
}






