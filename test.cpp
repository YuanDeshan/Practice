
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