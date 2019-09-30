#include <stdio.h>								
int find(int* arr,int left,int right,int a){
	int mid = 0;
	while (left <= right){
		mid = (left + right) / 2;
		if (arr[mid] > a){
			right = mid - 1;
		}
		else if(arr[mid]<a){
			left = mid + 1;
		}
		else{
			return mid;
		}
	}
	return -1;
}
int main(){	
	int f,z;
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int left = 0;
	int right = sizeof(a) / sizeof(a[0]) - 1;
	printf("������ҪѰ�ҵ���:\n");
	scanf("%d", &f);
	z = find(a, left, right, f);
	printf("%d\n", z);
	if (z >= 0){
		printf("�ҵ���!\n");
	}
	else{
		printf("û���ҵ�(-_-)\n");
	}
	return 0;								
}


