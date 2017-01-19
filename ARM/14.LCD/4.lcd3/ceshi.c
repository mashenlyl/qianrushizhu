#include <stdio.h>
#include "word.h"

#define RED 0xff0000

static void show_word(unsigned int x, unsigned int y, unsigned int color, unsigned char *data)  
{  
// count记录当前正在绘制的像素的次序
    int i=0, j, count = 0;  
	
	//我们这里的字模是8x25的，也就是宽是8，高是16的
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






