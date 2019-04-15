//#include <stdio.h>
//#include <assert.h>
//char* Strstr(const char* arr1,const char* arr2){
//	assert(arr1 != 0);
//	assert(arr2 != 0);
//	if (arr2 != "\0"){
//		return NULL;
//	}
//	const char* black_ptr = arr1;
//	while (*black_ptr != '\0'){
//		char* red_ptr = black_ptr;
//		const char* sub_ptr = arr2;
//		while (*red_ptr !=0
//			&& *sub_ptr !=0
//			&& *red_ptr==*sub_ptr){
//			++sub_ptr;
//			++red_ptr;
//		}
//		if (*sub_ptr == '\0'){
//			return black_ptr;
//		}
//		++black_ptr;
//	}
//	return NULL;
//}
//int main(){
//	char arr1[] = "ABCDEF";
//	char arr2[] = "DEF";
//	char* ret = Strstr(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}

#include <stdio.h>
#include <assert.h>
int Strcmp(const char* arr1, const char* arr2){
	assert(arr1 != 0);
	assert(arr2 != 0);
	int i = 0;
	for (i = 0; arr1[i] != '\0'; ++i){
		if (arr1[i] < arr2[i]){
			return -1;
		}
		else if (arr1[i] > arr2[i]){
			return 1;
		}
		else{

		}
	}
		if (arr1[i] < arr2[i]){
			return -1;
		}
		else if (arr1[i] > arr2[i]){
			return 1;
		}
		else{
			return 0;
		}
}
int main(){
	char arr1[] = "aaa";
	char arr2[] = "aba";
	char* ret = Strcmp(arr1, arr2);
	if (ret == 0){
		printf("arr1=arr2\n");
	}
	if (ret > 0){
		printf("arr1>arr2\n");
	}
	if (ret <0){
		printf("arr1<arr2\n");
	}
	return 0;
}