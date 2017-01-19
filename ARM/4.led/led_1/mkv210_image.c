/*
 * mkv210_image.c����Ҫ���þ�����usb����ʱʹ�õ�led.bin�����õ���sd�������ľ���210.bin
 *
 * ���ļ�����������֮�۵�����̳̣�������֮�۵��ĵ��н��������ļ���һ�����������ṩ���ڴ˱�ʾ��л��
 */
/* ��BL0�׶Σ�Irom�ڹ̻��Ĵ����ȡnandflash��SD��ǰ16K�����ݣ�
 * ���ȶ�ǰ16�ֽ��е�У����Ƿ���ȷ����ȷ�������������ֹͣ��
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFSIZE                 (16*1024)
#define IMG_SIZE                (16*1024)
#define SPL_HEADER_SIZE         16
//#define SPL_HEADER              "S5PC110 HEADER  "
#define SPL_HEADER              "****************"

int main (int argc, char *argv[])
{
	FILE		*fp;
	char		*Buf, *a;
	int		BufLen;
	int		nbytes, fileLen;
	unsigned int	checksum, count;
	int		i;
	
	// 1. 3������
	if (argc != 3)
	{
		printf("Usage: %s <source file> <destination file>\n", argv[0]);
		return -1;				//Ӧ�ñ�ʾ�����д������˼������Ҳûʲô�ð�
	}

	// 2. ����16K��buffer
	BufLen = BUFSIZE;
	Buf = (char *)malloc(BufLen);			//���亯��
	if (!Buf)
	{
		printf("Alloc buffer failed!\n");
		return -1;
	}

	memset(Buf, 0x00, BufLen);			//���ֵ��ȥ������0

	// 3. ��Դbin��buffer
	// 3.1 ��Դbin
	fp = fopen(argv[1], "rb");			//fopen�������ڴ��ļ�, ����ø�ʽΪ: FILE *fopen(char *filename, *type); 
	if( fp == NULL)
	{
		printf("source file open error\n");
		free(Buf);
		return -1;
	}
	// 3.2 ��ȡԴbin���ȣ�fseek����Ҳ������������,�൱�����ļ����ж�λ
	//  ���� ftell() ���ڵõ��ļ�λ��ָ�뵱ǰλ��������ļ��׵�ƫ���ֽ���
	fseek(fp, 0L, SEEK_END);								// ��λ���ļ�β
	fileLen = ftell(fp);									// �õ��ļ����Ⱥ���
	fseek(fp, 0L, SEEK_SET);								// �ٴζ�λ���ļ�ͷ
	// 3.3 Դbin���Ȳ��ó���16K-16byte
	count = (fileLen < (IMG_SIZE - SPL_HEADER_SIZE))
		? fileLen : (IMG_SIZE - SPL_HEADER_SIZE);
	// 3.4 buffer[0~15]���"S5PC110 HEADER  "
	//memcpy �������� ����Դ�ڴ棨src��ָ����ڴ����򣩿�����Ŀ���ڴ棨dest��ָ����ڴ����򣩣�
	//����ԭ�ͣ�void *memcpy(void *dest, void *src, unsigned int count);
	memcpy(&Buf[0], SPL_HEADER, SPL_HEADER_SIZE);
	// 3.5 ��Դbin��buffer[16]
	nbytes = fread(Buf + SPL_HEADER_SIZE, 1, count, fp);
	if ( nbytes != count )
	{
		printf("source file read error\n");
		free(Buf);
		fclose(fp);
		return -1;
	}
	fclose(fp);

	// 4. ����У���
 	// 4.1 �ӵ�16byte��ʼͳ��buffer�й��м���1
	// 4.1 �ӵ�16byte��ʼ���㣬��buffer�����е��ֽ����ݼӺ������õ��Ľ��
	a = Buf + SPL_HEADER_SIZE;
	for(i = 0, checksum = 0; i < IMG_SIZE - SPL_HEADER_SIZE; i++)
		checksum += (0x000000FF) & *a++;
	// 4.2 ��У��ͱ�����buffer[8~15]
	a = Buf + 8;							// Buf��210.bin����ʼ��ַ��+8��ʾ���λ��2���֣�Ҳ����˵д�뵽��3����
	*( (unsigned int *)a ) = checksum;

	// 5. ����buffer�е����ݵ�Ŀ��bin
	// 5.1 ��Ŀ��bin
	fp = fopen(argv[2], "wb");
	if (fp == NULL)
	{
		printf("destination file open error\n");
		free(Buf);
		return -1;
	}
	// 5.2 ��16k��buffer������Ŀ��bin��
	a = Buf;
	nbytes	= fwrite( a, 1, BufLen, fp);
	if ( nbytes != BufLen )
	{
		printf("destination file write error\n");
		free(Buf);
		fclose(fp);
		return -1;
	}

	free(Buf);
	fclose(fp);

	return 0;
}