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
	Stack* p=(Satck*)malloc(sizeof(STDatatype));
	if(p==null){
		assert(0);
		return ��
	}
	
}

//ѹջ
void StackPush(Stack* ps,STDatatype data){
	assert(ps);
	ps->arr[size]=data;
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
	return ps->size��
}

//��ջ�Ƿ�Ϊ��
int StackEmpty(Stack* ps){
	assert(ps);
}

//����ջ
void StackDestroy(Stack* ps){
	assert(ps);
}

//����
void StackTest(){
	assert(ps);

}

int main(){
	
	StackTest();
	return 0;
}
