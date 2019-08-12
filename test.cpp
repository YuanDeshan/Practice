
#include <string.h>
#include <iostream>
using namespace std;

int fun(int month){
	if (month<3){
		return 1;
	}
	else{
		int first = 1;
		int second = 1;
		int count;
		while (month>2){
			count = first + second;
			first = second;
			second = count;
			--month;
		}
		return count;
	}
}

int  main(){
	int month;
	cin >> month;
	cout << fun(month) << endl;
	return 0;
}

#if 0
void Print_Arr1(int arr[], int sz)
{
	for (int i = 0; i < sz; ++i)
	{
		printf("%d\n", arr[i]);
	}
}

void Print_Arr2(int* arr, int sz)
{
	for (int i = 0; i < sz; ++i)
	{
		printf("%d\n", arr[i]);
	}

}

void

int main()
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Print_Arr1(arr, sz);
	Print_Arr2(arr, sz);
	
	
	
	return 0;
}

int main()
{
	char str[] = "hehe";
	int lenth = strlen(str);
	printf("%d\n", lenth);
	return 0;
}

#endif


#if 0
int main()
{

	char str1[20] = "hehe";
	char str2[] = "haha";
	printf("%d\n", strcmp(str1, str2));
	return 0;
}
#endif

int My_Strcmp(const char* str1, const char* str2)
{
	assert(str1 != NULL);
	assert(str2 != NULL);
	int ret = 0;
	//先将2个字符串中字符转为无符号
	//str1-str2每个字符依次相减如果相等，结果为0，
	//则对结果取反，让条件为真，继续下一个字符的比较
	//直到将str1字符全部比较完
	while (!(ret=*(unsigned char*)str1-*(unsigned char*)str2)&&*str1)
	{
		++str1;
		++str2;
	}
	if (ret > 0)
	{
		ret = 1;
	}
	else if (ret < 0)
	{
		ret = -1;
	}
	return ret;
}
#if 0
int main()
{
	int *p = (int*)calloc(10,sizeof(int));
	if (p == NULL)
	{
		assert(0);
		return NULL;
	}
	int* ptr = NULL;
	 ptr = (int*)realloc(p, 20);
	if (p != NULL)
	{
		p = ptr;
	}
	for (int i = 0; i < 20; ++i)
	{
		printf("%d ", p[i]);
	}

	free(ptr);
	return 0;

}
#endif

#include <iostream>
using namespace std;


int main()
{
	int num = 0, new_num = 0, old_num = 0;
	int N;
	cin >> N;
	if (N == 1){
		num = 1;
	}
	else if (N == 2)
	{
		num = 2;
		
	}
	else
	{
		old_num = 2;
		for (int i = 2; i < N; ++i)
		{
			num = old_num * 2;
			old_num = num;
		}

	}
	cout << num << endl;
	return 0;
}

#if 0
int main()
{
	return 0;
}




