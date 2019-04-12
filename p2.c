#include <stdio.h>
#include <string.h>
int main1()
{
	int ch;
	printf("ÇëÊäÈëÒ»¸ö×Ö·û\n");
	ch = getchar();
	if ('a' <= ch&&ch <= 'z'){
		ch = ch - 32;
		putchar(ch);
	}
	else if ('A' < ch < 'Z'){
		ch = ch + 32;
		putchar(ch);
	}
	return 0;
}
