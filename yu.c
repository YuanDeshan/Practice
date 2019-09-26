#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(){
	
	int array[10]={1,2};
	char* p="hello";
	
	printf("%d %d\n",sizeof(array),sizeof(p));
	system("pause");
	return 0;
}