#include <stdio.h>					//����Ԥ��������
void mul(int row ){
	for (int i = 1; i <= row; i++){
		for (int j=1; j <= i; j++){
			printf("%d*%d=%d\t", i, j, i*j);
		}
		putchar('\n');
	}
}
int main(){							//����������
	int row;
	printf("����������:\n");
	scanf("%d", &row);
	mul(row);
	return 0;						//��������ֵΪ0
}