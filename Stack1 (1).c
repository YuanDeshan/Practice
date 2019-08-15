#include "stack.h"
#include <assert.h>
#include <malloc.h>
#include <stdio.h>
#define  N 10

//1.��ʼ��
void StackInit(Stack* ps)
{
	ps->_array = (SDatatype*)malloc(sizeof(SDatatype)*N);
	if (ps->_array == NULL)
	{
		assert(0);
		return;
	}
	ps->_capacity = N;
	ps->_size = 0;
}
//2.ѹջ
void StackPush(Stack* ps, SDatatype data)
{
	assert(ps);
	ps ->_array[ps->_size] = data;
	ps ->_size++;
}
//3.��ջ
void StackPop(Stack* ps)
{
	assert(ps);
	if (StackEmpty(ps)){
		return;
	}
	ps->_size--;
}
//4.��ȡջ��Ԫ��
SDatatype GetStackTop(Stack* ps)
{
	assert(ps);
	return ps->_array[ps->_size-1];
}
//5.�п�
int StackEmpty(Stack* ps)
{
	assert(ps);
	return 0 == ps->_size;
}
//6.��ȡջ��С
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_size;
}
//7.ջ������
void StackDestroy(Stack* ps)
{
	assert(ps);
	if (ps->_array)
	{
		free(ps->_array);
		ps->_array = NULL;
		ps->_capacity = 0;
		ps->_size = 0;
	}
}
//8.ջ�Ĳ���
void StackTest()
{
	Stack s;
	StackInit(&s);
	for (int i = 0; i < 5; ++i)
	{
	StackPush(&s, i);
	}
	StackPop(&s);
	printf("%d\n", GetStackTop(&s));
	printf("%d\n", StackSize(&s));

	StackDestroy(&s);


}
