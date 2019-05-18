#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <stdlib.h>

typedef int SDataType;

//����Ľڵ�
typedef struct SListNode{
	SDataType data;
	struct SListNode* pNext;
}Node,*PNode;
  
//����Ľṹ,��һ��ͷָ�뱣�������һ���ڵ�ĵ�ַ
typedef struct SList{
	PNode pHead;//ָ�������еĵ�һ���ڵ�
}SList,*PSList;

//����ĳ�ʼ��
void SlistInit(SList* s){
	assert(s);
	s->pHead = NULL;
}

//�����½ڵ�
PNode BuySListNode(SDataType data){
	PNode pNewNode = (PNode)malloc(sizeof(Node));
	if (pNewNode == NULL){
		assert(0);
		return NULL;
	}
	pNewNode->data = data;
	pNewNode->pNext = NULL;
	return pNewNode;
}

//β��
void SListPushBack(SList* s, SDataType data){
	assert(s);
	PNode pNewNode = BuySListNode(data);
	if (s->pHead==NULL){
		//������
		s->pHead=pNewNode;
	}
	else{
		//����ǿ�,�����������һ���ڵ�
		PNode pCur = s->pHead;
		while (pCur->pNext){
			pCur = pCur->pNext;
		}
		PNode pNewNode = BuySListNode(data);
		pCur->pNext = pNewNode;
	}
}

//βɾ
void SListPopBack(SList* s){
	assert(s);
	//������
	if (s->pHead==NULL){
		return;
	}
	//ֻ��һ���ڵ�
	else if (s->pHead->pNext==NULL){
		free(s->pHead);
		s->pHead = NULL;
	}
	//�������������Ͻڵ�
	else{
		PNode pPre = NULL;//pPre�������һ���ڵ����һ���ڵ�
		PNode pCur = s->pHead;
		while (pCur->pNext)
		{
			pPre = pCur;
			pCur = pCur->pNext;
		}
		free(pCur);//�ͷ����һ���ڵ�ռ�
		pPre->pNext = NULL;//��ǰһ���ڵ�ָ��NULL
	}
}

//ͷ��
void SListPushFront(SList* s,SDataType data){
	assert(s);
	PNode pNewNode = BuySListNode(data);
	pNewNode->pNext = s ->pHead;
	s->pHead = pNewNode;
}

//ͷɾ
void SListPopFront(SList* s){
	PNode pdelNode = NULL;
	assert(s);
	if (s->pHead==NULL){
		return;
	}
	pdelNode = s->pHead;
	s->pHead = pdelNode->pNext;
	free(pdelNode);
}

//����λ�ò���
void SListInsert(PNode pos, SDataType data){
	PNode pNewNode = NULL;
	if (pos==NULL){
		return;	
	}
	pNewNode = BuySListNode(data);
	pNewNode->pNext = pos->pNext;
	pos->pNext = pNewNode;
}

//����λ��ɾ��
void SListErase(SList* s, PNode pos){
	assert(s);
	if (pos == NULL || s->pHead==NULL){
		return;
	}
	if (pos==s->pHead){
		s->pHead = pos->pNext;
	}
	else{
		PNode pPrepos = s->pHead;
		while (pPrepos && pPrepos->pNext != pos){
			pPrepos = pPrepos->pNext;
		}
		if (pPrepos){
			pPrepos->pNext = pos->pNext;
		}
	}
	free(pos);
}

//���������е�Ԫ��
PNode SListFind(SList* s,SDataType data){
	assert(s);
	PNode pCur = s->pHead;
	while (pCur){
	if (pCur->data==data){
		return pCur;
	}
	pCur = pCur->pNext;
	}
	return NULL;
}

//��ȡ��ЧԪ�ظ���
size_t SListSize(SList* s){
	assert(s);
	PNode pCur = s->pHead;
	size_t count = 0;
	while (pCur){
		++count;
		pCur = pCur->pNext;
	}
	return count;
}

//��������Ƿ�Ϊ��
int SListEmpty(SList* s){
	assert(s);
	return s->pHead == NULL;
}

//�����Ч�ڵ�
int SListClear(SList* s){
	assert(s);
	PNode pCur = s->pHead;
	if (s->pHead== NULL){
		return 0;
	}
	while (s->pHead){
		pCur = s->pHead->pNext;
		free(s->pHead);
		s->pHead = pCur;
		}
	return 1;
}

//��������
void SListDestroy(SList* s){

}

//��ӡ����
void PrintSList(SList* s){
	assert(s);
	PNode pCur = s->pHead;
	while (pCur){
		printf("%d---->", pCur->data);
		pCur = pCur->pNext;
	}
	printf("NULL\n");
}

//����
void TestSList(){
	SList s;

	//��ʼ������
	SlistInit(&s);

	//β�����
	for (int i = 1; i < 6; ++i){
		SListPushBack(&s, i);
	}
	PrintSList(&s);

	//βɾ����
	SListPopBack(&s);
	PrintSList(&s);

	//ͷ�����
	SListPushFront(&s, 6);
	PrintSList(&s);

	//ͷɾ����
	SListPopFront(&s);
	PrintSList(&s);

	//����λ�ò������
	SListInsert(SListFind(&s,3),6 );
	PrintSList(&s);

	//����λ��ɾ������
	SListErase(&s,SListFind(&s, 4));
	PrintSList(&s);
	
	//���Ҳ���
	printf("%p\n", SListFind(&s, 1));

	//��Ч�ڵ��������
	printf("%d\n",SListSize(&s));

	//�пղ���
	printf("%d\n", SListEmpty(&s));

	//�����Ч�ڵ����
	//SListClear(&s);
	//PrintSList(&s);

	//�����������
	//SListDestroy(&s);
}


int main(){
	TestSList();
	system("pause");
	return 0;
}
