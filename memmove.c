#include<stdio.h> 
#include <assert.h>
#include <string.h>
void * Memmove(void * dest, const void * src, size_t count){
	void * ret = dest;
	if (dest <= src || (char *)dest >= ((char *)src + count)){
		while (count--){
			*(char *)dest = *(char *)src;
			dest = (char *)dest + 1;
			src = (char *)src + 1;
		}
	}
	else{
		dest = (char *)dest + count - 1;
		src = (char *)src + count - 1;
		while (count--){
			*(char *)dest = *(char *)src;
			dest = (char *)dest - 1;
			src = (char *)src - 1;
		}
		}
	return ret;
}
int main(){
	char arr1[1024] = "";
	char arr2[1024] = "ABCDEF";
	Memmove(arr1, arr2,4);
	printf("%s\n", arr1);
	return 0;
}

