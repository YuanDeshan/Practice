#include <stdio.h>								
void mul(int input){
	for (int i = 1; i <=input; i++){
		for (int j = 1; j <= i; j++){
			printf("%d*%d=%d\t", i, j, i*j);
		}
		putchar('\n');
	}
}
int main(){	
	int input;
	printf("������һ��������\n");
	scanf("%d", &input);
	mul(input);
	return 0;								
}


