#include <stdio.h>
#include <assert.h>
char* Strcat(char* dest, const char* src){//����һ���ַ���ƴ������
	//�������߲�Ϊ��
	assert(dest != NULL);
	assert(src != NULL);
	int i=0;
	//ѭ�������� ��i��Ӧ��Ԫ��Ϊ'\0'
	for ( i = 0; dest[i] != '\0'; ++i);
	//��src��Ԫ�����θ���dest
		for ( int j = 0; src[j] != '\0';++i ,++j){
			dest[i] = src[j];
		}
	return dest;
}
int main(){
	//���������ַ������飬�����г�ʼ��
	char arr1[1024] = "ABC";
	char arr2[1024] = "DEF"; 
	Strcat(arr1, arr2);//����Strcat
	printf("%s\n",arr1 );//���ƴ�Ӻ���ַ���
	return 0;
}