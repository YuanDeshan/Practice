#define  _CRT_SECURE_NO_WARNINGS
#include "SeqList.h"
#include <stdio.h>
#include <assert.h>
#include <malloc.h>

//1.初始化
void SeqListInit(SeqList* ps, int capacity)
{
	ps->_array = (SLDataType*)malloc(sizeof(SLDataType)*capacity);
	if (ps->_array == NULL)
	{
		assert(0);
		return;
	}
	ps->_size = 0;
	ps->_capacity = capacity;
}

//2.头插
void SeqListPushFront(SeqList* ps, SLDataType data)
{
	assert(ps);

	if (ps->_size == ps->_capacity)
	{
		SeqListCheckCapacity(ps);
	}

	for (int i = ps->_size-1; i >= 0; --i)
	{
		ps->_array[i + 1] = ps->_array[i];
	}
	ps->_array[0] = data;
	ps->_size++;
}
//3.尾插
void SeqListPushBack(SeqList* ps, SLDataType data)
{
	assert(ps);

	if (ps->_size == ps->_capacity)
	{
		SeqListCheckCapacity(ps);
	}
	ps->_array[ps->_size] = data;
	ps->_size++;
}
//4.指定插入
void SeqListInsert(SeqList* ps, int pos, SLDataType data)
{
	assert(ps);
	if (pos<0 || pos>ps->_size)
	{
		printf("输入位置不合法\n");
		return;
	}

	if (ps->_size == ps->_capacity)
	{
		SeqListCheckCapacity(ps);
	}

	for (int i = ps->_size - 1; i >= pos-1; --i)
	{
		ps->_array[i + 1] = ps->_array[i];
	}
	ps->_array[pos-1] = data;
	ps->_size++;
}
//5.头删
void SeqListPopFront(SeqList* ps)
{
	assert(ps);
	if (SeqListEmpty(ps))
	{
		return;
	}
	for (int i = 1; i < ps->_size - 1; ++i)
	{
		ps->_array[i - 1] = ps->_array[i];
	}
	ps->_size--;
}
//6.尾删
void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	if (SeqListEmpty(ps))
	{
		return;
	}
	ps->_size--;
}
//7.指定删除
void SeqListErase(SeqList* ps, int pos)
{
	assert(ps);
	if (pos<0 || pos>ps->_size)
	{
		printf("输入位置不合法\n");
		return;
	}
	if (SeqListEmpty(ps))
	{
		return;
	}
	for (int i = pos; i < ps->_size; ++i)
	{
		ps->_array[i - 1] = ps->_array[i];
	}
	ps->_size--;
}
//8.查找
int SeqListFind(SeqList* ps, SLDataType data)
{
	assert(ps);
	for (int i = 0; i < ps->_size; ++i)
	{
		if (ps->_array[i] == data)
		{
			return i + 1;
		}
	}
	return -1;
}
//9.修改
void SeqListModify(SeqList* ps, int pos, SLDataType data)
{
	assert(ps);
	ps->_array[pos - 1] = data;

}
//10.检测有效元素个数
int SeqListSize(SeqList* ps)
{
	assert(ps);
	return ps->_size;
}
//11.检测容量大小
int SeqListCapacity(SeqList* ps)
{
	assert(ps);
	return ps->_capacity;
}
//12.扩容
void SeqListCheckCapacity(SeqList* ps)
{
	assert(ps);
	if (ps->_size == ps->_capacity){
		int NewCapacity = ps->_capacity * 2;
		//1.申请新空间
		int* ptemp = (SLDataType*)malloc(NewCapacity*sizeof(SLDataType));
		if (ptemp == NULL)
		{
			assert(0);
			return;
		}
		//2.拷贝元素
		for (int i = 0; i < ps->_size; ++i)
		{
			ptemp[i] = ps->_array[i];
		}
		//3.释放旧空间
		free(ps->_array);
		//4.更新元素
		ps->_array = ptemp;
		ps->_capacity = NewCapacity;
	}
}
//13.清空
void SeqListClear(SeqList* ps)
{
	assert(ps);
	ps->_size = 0;
}
//14.销毁
void SeqListDestroy(SeqList* ps)
{
	assert(ps);
	free(ps->_array);
	ps->_array = NULL;
	ps->_size = 0;
	ps->_capacity = 0;
}
//15.打印
void SeqListPrint(SeqList* ps)
{
	assert(ps);
	printf("SeqListPrint: ");
	for (int i = 0; i < ps->_size; ++i)
	{
		printf("%d   ", ps->_array[i]);
	}
	putchar('\n');
}
//16.测试
void SeqListTest()
{
	SeqList sl;
	SeqListInit(&sl,1024);

	for (int i = 10; i >0; --i)
	{
	SeqListPushFront(&sl, i);
	}
	SeqListPrint(&sl);

	//SeqListPushBack(&sl, 11);
	//SeqListPrint(&sl);

	/*int pos, data;
	printf("请输入要插入的位置及数据：");
	scanf("%d%d", &pos,&data);
	SeqListInsert(&sl, pos, data);
	SeqListPrint(&sl);*/

	SeqListPopFront(&sl);
	SeqListPrint(&sl);

	SeqListPopBack(&sl);
	SeqListPrint(&sl);

	/*int pos;
	printf("请输入要删除的位置：");
	scanf("%d", &pos);
	SeqListErase(&sl, pos);
	SeqListPrint(&sl);*/

	//printf("您要查找的数据位置为：%d\n", SeqListFind(&sl, 6));

	printf("%d\n", SeqListSize(&sl));
	printf("%d\n", SeqListCapacity(&sl));

	/*SeqListClear(&sl);
	SeqListPrint(&sl);*/

	/*SeqListModify(&sl, 1, 329);
	SeqListPrint(&sl);*/

	SeqListDestroy(&sl);

}
//17.判空
int SeqListEmpty(SeqList* ps)
{
	assert(ps);
	return 0 == ps->_size;
}

