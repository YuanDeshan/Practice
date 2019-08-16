#pragma  once

typedef int QDataType;

typedef struct QNode
{
	struct QNode* _next;//指针域
	QDataType _data;//数据域
	
}QNode;

typedef struct Queue
{
	QNode* _front;//指向队头元素
	QNode* _rear;//指向队尾元素
}Queue;

//1.队列初始化
void QueueInit(Queue* ps);
//2.进队列
void QueuePush(Queue* ps, QDataType data);
//3.出队列
void QueuePop(Queue* ps);
//4.获取队头元素
QDataType GetQueueFront(Queue* ps);
//5.获取队尾元素
QDataType GetQueuerear(Queue* ps);
//销毁队列
void QueueDestroy(Queue* ps);
//判空
int QueueEmpty(Queue* ps);
//获取队列有效元素个数
int QueueSize(Queue* ps);
//测试
void QueueTest();
