#pragma once

typedef int SDatatype;

typedef struct Stack
{
	SDatatype* _array;
	int _top;//栈顶
	int _size;//有效元素个数
	int _capacity;//容量

}Stack;

//1.初始化
void StackInit(Stack* ps);
//2.压栈
void StackPush(Stack* ps,SDatatype data);
//3.出栈
void StackPop(Stack* ps);
//4.获取栈顶元素
SDatatype GetStackTop(Stack* ps);
//5.判空
int StackEmpty(Stack* ps);
//6.获取栈大小
int StackSize(Stack* ps);
//7.栈的销毁
void StackDestroy(Stack* ps);
//8.栈的测试
void StackTest();
