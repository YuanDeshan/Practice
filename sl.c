#include <stdio.h>
int mian(){

	int* a=1;
	char* p=(char*)&a;
	printf("%d",*p);
	return 0;
}