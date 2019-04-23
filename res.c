#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(){
	int n;
	printf("请输入一个整数：\n");
	scanf("%d", &n);
	while(n){
		printf("%d", n%10);
		n /= 10;
	}
	putchar('\n');
	system("pause");
	return 0;
}