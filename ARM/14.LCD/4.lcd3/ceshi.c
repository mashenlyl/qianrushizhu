#include <stdio.h>
#include "word.h"

#define RED 0xff0000

static void show_word(unsigned int x, unsigned int y, unsigned int color, unsigned char *data)  
{  
// count��¼��ǰ���ڻ��Ƶ����صĴ���
    int i=0, j, count = 0;  
	
	//�����������ģ��8x25�ģ�Ҳ���ǿ���8������16��
		for (j=y; j<(y+80); j++)  
		{ 
				printf("%2x", data[j]);  
		}
		printf("\n");

} 

void draw_word_ok(unsigned int x, unsigned int y, unsigned int color)
{
	int i = 0;  
	unsigned char *ch;
		ch = (unsigned char *)word[i];
        show_word(x, y, color, ch); 
		
        x += 8;
}

int main (void)
{
	draw_word_ok(0,0,RED);
	
	return 0;
}






