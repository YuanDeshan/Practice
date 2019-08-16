#include "Queue.h"
#include <stdio.h>
#include <assert.h>
#include <malloc.h>

//1.队列初始化
void QueueInit(Queue* ps)
{
	assert(ps);
	ps->_front = NULL;
	ps->_rear = NULL;
}
QNode* BuyQueueNode(QDataType data)
{
	QNode* pNewNode = (QNode*)malloc(sizeof(QNode));
	if (pNewNode == NULL)
	{
		assert(0);
		return NULL;
	}
	pNewNode->_data = data;
	pNewNode->_next = NULL;
	return pNewNode;

}


//2.进队列
void QueuePush(Queue* ps, QDataType data)
{
	assert(ps);
	QNode* pNewNode = BuyQueueNode(data);
	if (QueueEmpty(ps))
	{
		ps->_front = pNewNode;
		ps->_rear = pNewNode;
	}
	else
	{
		ps->_rear->_next = pNewNode;
		ps->_rear = pNewNode;
	}

}
//3.出队列
void QueuePop(Queue* ps)
{
	assert(ps);
	QNode* DelNode = NULL;
	if (QueueEmpty(ps))
	{
		return;
	}
	DelNode = ps->_front;
	if (ps->_front->_next == NULL)
	{
		ps->_front = NULL;
		ps->_rear = NULL;
	}
	else
	{
		ps->_front = DelNode->_next;
	}
	free(DelNode);
}
//4.获取队头元素
QDataType GetQueueFront(Queue* ps)
{
	assert(ps);
	return ps->_front->_data;
}
//5.获取队尾元素
QDataType GetQueuerear(Queue* ps)
{
	assert(ps);
	return ps->_rear->_data;

}
//销毁队列
void QueueDestroy(Queue* ps)
{
	assert(ps);
	QNode* pCur = ps->_front;
	while (pCur)
	{
		ps->_front = pCur->_next;
		free(pCur);
		pCur = ps->_front;
	}
}
//判空
int QueueEmpty(Queue* ps)
{
	assert(ps);
	return NULL==ps->_front;
}
//获取队列有效元素个数
int QueueSize(Queue* ps)
{
	int size = 0;
	QNode* pCur = ps->_front;
	while (pCur)
	{
		++size;
		pCur = pCur->_next;
	}
	return size;

}
//测试
void QueueTest()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePop(&q);
	printf("%d\n", QueueSize(&q));
}
