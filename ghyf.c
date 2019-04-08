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
//	printf("请输入一个整数:\n");
//	scanf("%d", &n);
//	a = DigitSum(n);
//	printf("%d\n",a);
//	return 0;
//}


//#include <stdio.h>
//void reverse_string(char *s){
//	int len = my_strlen(string);//调用上面的字符串长度函数;
//	if (len <= 1)	//当字符串长度小于等于1时，不执行；
//		return;
//	else
//	{
//		char temp = s[0];	 //将第一个字符的值保存在temp中;
//		s[0] = s[len - 1];//将最后一个字符赋给第一个字符;
//		s[len - 1] = '\0';	//将最后一个字符的内容赋为'\0';
//		reverse_string(string + 1);//递归调用下一次反转；
//		string[len - 1] = temp;	//将temp赋给当前的最后一个字符；
//	}
//}
//int main(){
//	char *s = "abcdefg";
//	reverse_string(s);
//	return 0;
//}

//求长度非递归

//#include <stdio.h>
//#include <string.h>
//int main(){
//	char* s = "abcde1234j";
//	int len;
//	len = strlen(s);
//	printf("%d\n", len);
//	return 0;
//}

//求长度递归

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


//6.非递归求阶乘

//#include <stdio.h>
//int main(){
//	int n, i,sum=1;
//	printf("请输入一个整数:\n");
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++){
//		sum *= i;
//	}
//	printf("%d\n", sum);
//	return 0;
//}

//6.递归求阶乘

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
//	printf("请输入一个整数:\n");
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
	printf("请输入一个整数:\n");
	scanf("%d", &n);
	bit(n);
	putchar('\n');
	system("pause");
	return 0;
}






