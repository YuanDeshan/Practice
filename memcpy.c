#include<stdio.h> 
#include <assert.h>
#include <string.h>
void* Memcpy (void* dest,const void* src,size_t count){
	void* ret = dest;
	assert(dest);
	assert(src);
	while (--count){
		*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
	}
	return ret;
}

int main(){
	char arr1[1024] = "";
	const char arr2[1024] = "ABCDEF";
	Memcpy(arr1, arr2,strlen(arr2)+1);
	printf("%s\n", arr1);
	return 0;
}

