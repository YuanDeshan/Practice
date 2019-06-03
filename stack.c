#include <stdio.h>
#include <assert.h>
#include <malloc.h>

typedef int STDatatype;

typedef struct Stack{
	STDatatype* arr;
	int top;//栈顶
	int capacity;//容量
}Stack;

//栈初始化
void StackInit(Stack* ps){
	assert(ps);
}

//压栈
void StackPush(Stack* ps,STDatatype data){
	assert(ps);
}

//出栈
void StackPop(Stack* ps){
	assert(ps);
}

//栈顶
STDatatype StackTop(Stack* ps){
	assert(ps);
}

//求栈有效元素个数
int StackSize(Stack* ps){
	assert(ps);
}

//段栈是否为空
int StackEmpty(Stack* ps){

}

//销毁栈
void StackDestroy(Stack* ps){

}

//测试
void StackTest(){


}

int main(){
	StackTest();
	return 0;
}
