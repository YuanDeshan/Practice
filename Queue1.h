#pragma  once

typedef int QDataType;

typedef struct QNode
{
	struct QNode* _next;//ָ����
	QDataType _data;//������
	
}QNode;

typedef struct Queue
{
	QNode* _front;//ָ���ͷԪ��
	QNode* _rear;//ָ���βԪ��
}Queue;

//1.���г�ʼ��
void QueueInit(Queue* ps);
//2.������
void QueuePush(Queue* ps, QDataType data);
//3.������
void QueuePop(Queue* ps);
//4.��ȡ��ͷԪ��
QDataType GetQueueFront(Queue* ps);
//5.��ȡ��βԪ��
QDataType GetQueuerear(Queue* ps);
//���ٶ���
void QueueDestroy(Queue* ps);
//�п�
int QueueEmpty(Queue* ps);
//��ȡ������ЧԪ�ظ���
int QueueSize(Queue* ps);
//����
void QueueTest();
