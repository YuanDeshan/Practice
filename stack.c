#include <stdio.h>
#include <assert.h>
#include <malloc.h>

typedef int STDatatype;

typedef struct Stack{
	STDatatype* arr;
	int top;//ջ��
	int capacity;//����
}Stack;

//ջ��ʼ��
void StackInit(Stack* ps){
	assert(ps);
}

//ѹջ
void StackPush(Stack* ps,STDatatype data){
	assert(ps);
}

//��ջ
void StackPop(Stack* ps){
	assert(ps);
}

//ջ��
STDatatype StackTop(Stack* ps){
	assert(ps);
}

//��ջ��ЧԪ�ظ���
int StackSize(Stack* ps){
	assert(ps);
}

//��ջ�Ƿ�Ϊ��
int StackEmpty(Stack* ps){

}

//����ջ
void StackDestroy(Stack* ps){

}

//����
void StackTest(){


}

int main(){
	StackTest();
	return 0;
}
