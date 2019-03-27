#include <stdio.h>					//编译预处理命令
void mul(int row ){
	for (int i = 1; i <= row; i++){
		for (int j=1; j <= i; j++){
			printf("%d*%d=%d\t", i, j, i*j);
		}
		putchar('\n');
	}
}
int main(){							//定义主函数
	int row;
	printf("请输入行数:\n");
	scanf("%d", &row);
	mul(row);
	return 0;						//函数返回值为0
}