#pragma once

typedef int SDatatype;

typedef struct Stack
{
	SDatatype* _array;
	int _top;//ջ��
	int _size;//��ЧԪ�ظ���
	int _capacity;//����

}Stack;

//1.��ʼ��
void StackInit(Stack* ps);
//2.ѹջ
void StackPush(Stack* ps,SDatatype data);
//3.��ջ
void StackPop(Stack* ps);
//4.��ȡջ��Ԫ��
SDatatype GetStackTop(Stack* ps);
//5.�п�
int StackEmpty(Stack* ps);
//6.��ȡջ��С
int StackSize(Stack* ps);
//7.ջ������
void StackDestroy(Stack* ps);
//8.ջ�Ĳ���
void StackTest();
