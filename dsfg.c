#define use _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define price 1
int water_bottle(money){
	int empty_bottle = money / price;
	int full_bottle = money / price;
	while (empty_bottle > 1)
	{
		full_bottle += empty_bottle / 2;
		empty_bottle = empty_bottle / 2 + empty_bottle % 2;
	}
	return full_bottle;
}
int main(){
	int money;
	int num;
	printf("��������:\n");
	scanf("%d", &money);
	num = water_bottle(money);
	printf("���Ժ�%dƿ��ˮ!\n", num);
	
	return 0;
}