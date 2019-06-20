#include <iostream>
using namespace std;

#if 0
#include <iostream>
namespace N{
	int a=10;
	int b=20;
}
int main(){
	printf("%d\n", N::b);
	
	return 0;

}
#endif

#if 0
int Add(int a, char b){
	return a + b;
}

int Add(char a, int b){
	return a + b;
}

int main(){
	int a = 10;
	int b = 20;
	cout<<Add('B', 20)<<endl;
	cout << Add(10, 'A') << endl;

	return 0;
}
#endif

#if 0
extern "C" int Add(int a, int b);
double Add(double a, double b);

int main(){
	Add(1, 2);
	Add(1.0, 2.0);
	return 0;
}
#endif

#if 0
void Test(){
	int a=1024;
	int& ra = a;
	cout << "a=" << a << " " << "a的地址为：" << &a << endl;
	cout << "ra=" << a << " " << "ra的地址为：" << &ra << endl;
}

int main(){
	Test();
	return 0;
}
#endif




