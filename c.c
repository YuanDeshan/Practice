#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>					//编译预处理命令
int main(){
	
	int I;
	
	printf("请输入你的工资:\n");
	scanf("%d", &I);
	if (I <= 100000){
	bonus =I+ I * 0.1;
	printf("%d\n", bonus);
	}
	if (I > 100000 && I <= 200000){
	bonus = I + 100000 * 0.1
	+(I - 100000)*0.075;
	}
	if (I > 200000 && I <= 400000){
	bonus = I + 100000 * 0.1
	+ 100000 * 0.075
	+ (I - 200000)*0.05;
	}
	if (I > 400000 && I <= 600000){
	bonus = I + 100000 * 0.1
	+ 100000 * 0.075
	+ 200000*0.05
	+(I-400000)*0.03;
	}
	if (I > 600000 && I <= 1000000){
	bonus = I + 100000 * 0.1
	+ 100000 * 0.075
	+ 200000 * 0.05
	+ 200000 * 0.03
	+ (I - 600000)*0.015;
	}
	if (I > 1000000){
	bonus = I + 100000 * 0.1
	+ 100000 * 0.075
	+ 200000 * 0.05
	+ 200000 * 0.03
	+ 400000*0.015
	+(I-1000000)*0.01;
	}
	printf("%lf\n", bonus);
	
	return 0;						//函数返回值为0
}