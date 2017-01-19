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
	// ��һ�ֻ�ȡʱ���ֵ
	tNow1 = time(NULL);
	// �ڶ���
	time(&tNow2);
	
	memset(buf, 0, sizeof(buf));
	printf("tNow1 = %ld\n", tNow1);				//tNow1 = 1477120354
	printf("tNow2 = %ld\n", tNow2);				//tNow2 = 1477120354	���һ��
	printf("ctime = [%s]\n", ctime(&tNow1));
	// ����������޴��Ķ�����char *buf��Ȼ��buf��ȥ������ʵ��Ҫ����һ��char���͵�����ſ��Եģ�
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





