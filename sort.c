//#include <stdio.h>
//#include <stdlib.h>
//#define N 9  //宏定义:用一个N来表示数组大小
//void sort(int arr[], int len){//定义一个无返回值排序函数
//	//将数组分为2部分,左边下标用left,右边下标用right表示
//	int left = 0;
//	int right = len-1;//右边下标起始位置为数组长度减一
//	int temp;//定义一个整形中间变量
//	while (left < right){//当left<righ说明,该数组没有遍历完
//		//如果arr[left]为奇数,则该元素的位置不变,继续判断下一个元素
//		if (arr[left] % 2 == 1){
//			++left;
//		}
//		//如果arr[left]为偶数,则将它与最后一个元素交换,
//		//同时将righ自身减一,变成倒数第二个元素下标
//		//再判断交换后arr[left]的奇偶性
//		else if (arr[left] % 2 == 0){
//			temp = arr[left];
//			arr[left] = arr[right];
//			arr[right] = temp;
//			--right;
//		}
//	}
//	//输出排序完成后的数组
//	for (int i = 0; i < N; ++i){
//		printf("%d\t", arr[i]);
//	}
//	putchar('\n');
//
//}
//int main(){
//	int len = 0;//定义一个整形变量用来存储数组的长度
//	int arr[N] = { 0 };//定义一个整形数组,并进行初始化
//	printf("请输入一组整数：\n");//提示输入
//	//对数组进行输入赋值
//	for (int i = 0; i < N; ++i){
//		scanf("%d", &arr[i]);
//	}
//	len = sizeof(arr) / sizeof(arr[0]);//求取数组长度
//	sort(arr, len);//调用sort函数
//
//	return 0;//函数返回值为0
//}

#include <stdio.h>
#include <stdlib.h>
int find_num(int arr[3][3],int a){
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			if (arr[i][j] == a){
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	int arr[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int a,judg;
	printf("请输入要寻找的数:\n");
	scanf("%d", &a);
	judg = find_num(arr, a);
	if (judg==1){
		printf("找到了!\n");
	}
	else{
		printf("没有找到\n");
	}
	system("pause");
	return 0;
}