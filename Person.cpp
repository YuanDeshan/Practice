#define _CRT_SECURE_NO_WARNINGS
#include "Person.h"
#include <iostream>
#include <string.h>
using namespace std;

#if 0
int main(){
	auto a=10;
	auto b = 0.1;
	auto c = 'a';
	//auto d;
	cout << "a的类型是:" << typeid(a).name() << endl;
	cout << "b的类型是:" << typeid(b).name() << endl;
	cout << "c的类型是:" << typeid(c).name() << endl;
	//cout << "d的类型是:" << typeid(a).name() << endl;
	return 0;
}
#endif

//auto关键字
#if 0
int main(){
	int array[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	for (auto i : array){
		cout << i << "  ";
	}
	cout << endl;
	return 0;
}
#endif

//类与对象

#if 0
void Person::InitPerson(char* name,char* gender,int age){
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

void Person::PrintPerson(){
		cout << _name << _gender << _age << endl;
	}


int main(){
	Person p1;
	Person p2;
	p1.InitPerson("李四", "男", 20);
	
	p2.InitPerson("张三", "男", 30);

	return 0;
}
#endif



int Add(int a, int b){
	a += b;
	return a;
}

int main(){
	int a, b;
	cin >> a >> b;
	cout << Add(a, b) << endl;
	return 0;
}