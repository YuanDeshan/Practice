#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int fac(int n){
		if (n <= 1){
			return 1;
		}
		else{
			return n*fac(n - 1);
		}
	}
int main(){
	int n;
	printf("请输入一个整数:\n");
	scanf("%d", &n);
	printf("%d\n", fac(n));
	return 0;
}