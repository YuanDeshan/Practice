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

}

//压栈
void StackPush(Stack* ps,STDatatype data){

}

//出栈
void StackPop(Stack* ps){

}

//栈顶
STDatatype StackTop(Stack* ps){

}

//求栈有效元素个数
int StackSize(Stack* ps){

}

//段栈是否为空
int StackEmpty(Stack* ps){

}

void StackDestroy(Stack* ps){

}

void StackTest(){


}

int main(){
	StackTest();
	return 0;
}
