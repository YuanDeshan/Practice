//#include <stdio.h>
//#include <stdlib.h>
//#define N 9  //�궨��:��һ��N����ʾ�����С
//void sort(int arr[], int len){//����һ���޷���ֵ������
//	//�������Ϊ2����,����±���left,�ұ��±���right��ʾ
//	int left = 0;
//	int right = len-1;//�ұ��±���ʼλ��Ϊ���鳤�ȼ�һ
//	int temp;//����һ�������м����
//	while (left < right){//��left<righ˵��,������û�б�����
//		//���arr[left]Ϊ����,���Ԫ�ص�λ�ò���,�����ж���һ��Ԫ��
//		if (arr[left] % 2 == 1){
//			++left;
//		}
//		//���arr[left]Ϊż��,���������һ��Ԫ�ؽ���,
//		//ͬʱ��righ�����һ,��ɵ����ڶ���Ԫ���±�
//		//���жϽ�����arr[left]����ż��
//		else if (arr[left] % 2 == 0){
//			temp = arr[left];
//			arr[left] = arr[right];
//			arr[right] = temp;
//			--right;
//		}
//	}
//	//���������ɺ������
//	for (int i = 0; i < N; ++i){
//		printf("%d\t", arr[i]);
//	}
//	putchar('\n');
//
//}
//int main(){
//	int len = 0;//����һ�����α��������洢����ĳ���
//	int arr[N] = { 0 };//����һ����������,�����г�ʼ��
//	printf("������һ��������\n");//��ʾ����
//	//������������븳ֵ
//	for (int i = 0; i < N; ++i){
//		scanf("%d", &arr[i]);
//	}
//	len = sizeof(arr) / sizeof(arr[0]);//��ȡ���鳤��
//	sort(arr, len);//����sort����
//
//	return 0;//��������ֵΪ0
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
	printf("������ҪѰ�ҵ���:\n");
	scanf("%d", &a);
	judg = find_num(arr, a);
	if (judg==1){
		printf("�ҵ���!\n");
	}
	else{
		printf("û���ҵ�\n");
	}
	system("pause");
	return 0;
}