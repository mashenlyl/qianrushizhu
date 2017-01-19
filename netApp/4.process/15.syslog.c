#include <stdio.h>
#include <syslog.h>


int main(void)
{
	printf("开始\n");
	openlog("a.out", LOG_CONS | LOG_PID, LOG_USER);
	syslog(LOG_INFO, "This is a log\n");
	closelog();
	printf("结束\n");
	
	return 0;
}