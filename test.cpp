
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


int main()
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Print_Arr1(arr, sz);
	Print_Arr2(arr, sz);
	return 0;
}
#endif
