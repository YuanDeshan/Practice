#pragma once

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* _array;//ָ��̬�洢������
	int _size;//��ЧԪ�ظ���
	int _capacity;//�����ռ��С
}SeqList;

//1.��ʼ��
void SeqListInit(SeqList* ps, int capacity);
//2.ͷ��
void SeqListPushFront(SeqList* ps, SLDataType data);
//3.β��
void SeqListPushBack(SeqList* ps, SLDataType data);
//4.ָ������
void SeqListInsert(SeqList* ps, int pos, SLDataType data);
//5.ͷɾ
void SeqListPopFront(SeqList* ps);
//6.βɾ
void SeqListPopBack(SeqList* ps);
//7.ָ��ɾ��
void SeqListErase(SeqList* ps, int pos);
//8.����
int SeqListFind(SeqList* ps, SLDataType data);
//9.�޸�
void SeqListModify(SeqList* ps, int pos, SLDataType data);
//10.�����ЧԪ�ظ���
int SeqListSize(SeqList* ps);
//11.���������С
int SeqListCapacity(SeqList* ps);
//12.����
void SeqListCheckCapacity(SeqList* ps);
//13.���
void SeqListClear(SeqList* ps);
//14.����
void SeqListDestroy(SeqList* ps);
//15.��ӡ
void SeqListPrint(SeqList* ps);
//16.����
void SeqListTest();
//17.�п�
int SeqListEmpty(SeqList* ps);
