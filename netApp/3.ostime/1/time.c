#include <stdio.h>
#include <time.h>
#include <string.h>
#include <sys/time.h>

int main(void)
{
	time_t tNow1 = 0;
	time_t tNow2 = 0;
	char buf[40] = {0};
	struct tm result;
	struct timeval tv; 
	struct timezone tz;
	
	tNow1 = time(NULL);
	
#if 0
	// 第一种获取时间的值
	tNow1 = time(NULL);
	// 第二种
	time(&tNow2);
	
	memset(buf, 0, sizeof(buf));
	printf("tNow1 = %ld\n", tNow1);				//tNow1 = 1477120354
	printf("tNow2 = %ld\n", tNow2);				//tNow2 = 1477120354	结果一样
	printf("ctime = [%s]\n", ctime(&tNow1));
	// 我在这里很愚蠢的定义了char *buf，然后传buf进去，我们实际要定义一个char类型的数组才可以的；
	ctime_r(&tNow1, buf);
	printf("ctime_r = [%s]\n", buf);
#endif
	printf("tNow1 = %ld\n", tNow1);
	localtime_r(&tNow1, &result);
	printf("time: %d-%d-%d-%d-%d-%d\n", result.tm_year, result.tm_mon, result.tm_mday, result.tm_hour, result.tm_min, result.tm_sec);
	gmtime_r(&tNow1, &result);
	printf("time: %d-%d-%d-%d-%d-%d\n", result.tm_year, result.tm_mon, result.tm_mday, result.tm_hour, result.tm_min, result.tm_sec);
	asctime_r(&result, buf);
	printf("asctime_r = [%s]\n", buf);
	printf("mktime = %ld\n", mktime(&result));
	
	memset(buf, 0, sizeof(buf));
	strftime(buf, sizeof(buf), "%Y-%m-%d", &result);
	printf("time = %s\n", buf);
	
	gettimeofday(&tv, &tz);
	printf("tv_sec = %ld, tv_usec = %ld\n", tv.tv_sec, tv.tv_usec);
	printf("tz_minuteswest = %d, tz_dsttime = %d\n", tz.tz_minuteswest, tz.tz_dsttime);
	
	return 0;
}





