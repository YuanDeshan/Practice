#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>					//����Ԥ��������
int main(){
	int h = 10;
	float x1 = 2.0, y1 = 2.0,
		x2 = -2.0, y2 = 2.0,
		x3 = -2.0, y3 = -2.0,
		x4 = 2.0, y4 = -2.0,
		d1, d2, d3, d4, x, y;
	printf("����������(x,y):\n");
	scanf("%f,%f", &x, &y);
	d1 = (x - x1)*(x - x1) + (y - y1)*(y - y1);
	d2 = (x - x2)*(x - x2) + (y - y2)*(y - y2);
	d3 = (x - x3)*(x - x3) + (y - y3)*(y - y3);
	d4 = (x - x4)*(x - x4) + (y - y4)*(y - y4);
	if (d1 > 1 && d2 > 1 && d3 > 1 && d4 > 1){
		h = 0;
		printf("�߶�=%d\n", h);
	}
	else
		printf("�߶�=%d\n", h);
	return 0;						//��������ֵΪ0
}