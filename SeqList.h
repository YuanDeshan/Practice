#pragma once

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* _array;//指向动态存储的数组
	int _size;//有效元素个数
	int _capacity;//容量空间大小
}SeqList;

//1.初始化
void SeqListInit(SeqList* ps, int capacity);
//2.头插
void SeqListPushFront(SeqList* ps, SLDataType data);
//3.尾插
void SeqListPushBack(SeqList* ps, SLDataType data);
//4.指定插入
void SeqListInsert(SeqList* ps, int pos, SLDataType data);
//5.头删
void SeqListPopFront(SeqList* ps);
//6.尾删
void SeqListPopBack(SeqList* ps);
//7.指定删除
void SeqListErase(SeqList* ps, int pos);
//8.查找
int SeqListFind(SeqList* ps, SLDataType data);
//9.修改
void SeqListModify(SeqList* ps, int pos, SLDataType data);
//10.检测有效元素个数
int SeqListSize(SeqList* ps);
//11.检测容量大小
int SeqListCapacity(SeqList* ps);
//12.扩容
void SeqListCheckCapacity(SeqList* ps);
//13.清空
void SeqListClear(SeqList* ps);
//14.销毁
void SeqListDestroy(SeqList* ps);
//15.打印
void SeqListPrint(SeqList* ps);
//16.测试
void SeqListTest();
//17.判空
int SeqListEmpty(SeqList* ps);
