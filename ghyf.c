//#include <stdio.h>
//int DigitSum(int n)
//{
//	int sum = 0;
//	int m = 0;
//	if (n != 0)
//	{
//		m = n % 10;
//		n = n / 10;
//		sum = m + DigitSum(n);
//	}
//	return sum;
//}
//int main()
//{
//	int n,a;
//	printf("������һ������:\n");
//	scanf("%d", &n);
//	a = DigitSum(n);
//	printf("%d\n",a);
//	return 0;
//}


//#include <stdio.h>
//void reverse_string(char *s){
//	int len = my_strlen(string);//����������ַ������Ⱥ���;
//	if (len <= 1)	//���ַ�������С�ڵ���1ʱ����ִ�У�
//		return;
//	else
//	{
//		char temp = s[0];	 //����һ���ַ���ֵ������temp��;
//		s[0] = s[len - 1];//�����һ���ַ�������һ���ַ�;
//		s[len - 1] = '\0';	//�����һ���ַ������ݸ�Ϊ'\0';
//		reverse_string(string + 1);//�ݹ������һ�η�ת��
//		string[len - 1] = temp;	//��temp������ǰ�����һ���ַ���
//	}
//}
//int main(){
//	char *s = "abcdefg";
//	reverse_string(s);
//	return 0;
//}

//�󳤶ȷǵݹ�

//#include <stdio.h>
//#include <string.h>
//int main(){
//	char* s = "abcde1234j";
//	int len;
//	len = strlen(s);
//	printf("%d\n", len);
//	return 0;
//}

//�󳤶ȵݹ�

//#include <stdio.h>
//int len(char *s){
//	if (*s == '\0'){
//		return 0;
//	}
//	else {
//		return len(++s) + 1;
//	}
//}
//int main(){
//	char* s = "abcd123sdf";
//	int a;
//	a = len(s);
//	printf("%d\n", a);
//	return 0;
//}


//6.�ǵݹ���׳�

//#include <stdio.h>
//int main(){
//	int n, i,sum=1;
//	printf("������һ������:\n");
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++){
//		sum *= i;
//	}
//	printf("%d\n", sum);
//	return 0;
//}

//6.�ݹ���׳�

//#include <stdio.h>
//int fac(int n){
//	if (n <= 1){
//		return 1;
//	}
//	else{
//		return n*fac(n - 1);
//	}
//}
//int main(){
//	int n;
//	printf("������һ������:\n");
//	scanf("%d", &n);
//	printf("%d\n", fac(n));
//}



#include <stdio.h>
void bit(int n){
	if (n < 10){
		printf("%d ",n);
	}
	else{
		bit(n / 10);
		printf("%d ", n % 10);
	}
}
int main(){
	int n;
	printf("������һ������:\n");
	scanf("%d", &n);
	bit(n);
	putchar('\n');
	system("pause");
	return 0;
}






