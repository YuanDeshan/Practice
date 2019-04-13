#include <stdio.h>
#include <assert.h>
char* Strcat(char* dest, const char* src){//定义一个字符串拼接数组
	//断言两者不为空
	assert(dest != NULL);
	assert(src != NULL);
	int i=0;
	//循环结束后 ，i对应的元素为'\0'
	for ( i = 0; dest[i] != '\0'; ++i);
	//将src的元素依次赋给dest
		for ( int j = 0; src[j] != '\0';++i ,++j){
			dest[i] = src[j];
		}
	return dest;
}
int main(){
	//定义两个字符型数组，并进行初始化
	char arr1[1024] = "ABC";
	char arr2[1024] = "DEF"; 
	Strcat(arr1, arr2);//调用Strcat
	printf("%s\n",arr1 );//输出拼接后的字符串
	return 0;
}