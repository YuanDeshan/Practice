#include <stdio.h>
int DigitSum(int n)
{
	int sum = 0;
	int m = 0;
	if (n != 0)
	{
		m = n % 10;
		n = n / 10;
		sum = m + DigitSum(n);
	}
	return sum;
}
int main()
{
	int n, a;
	printf("������һ������:\n");
	scanf("%d", &n);
	a = DigitSum(n);
	printf("%d\n", a);
	return 0;
}