#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <stdlib.h>

typedef int SDataType;

//链表的节点
typedef struct SListNode{
	SDataType data;
	struct SListNode* pNext;
}Node,*PNode;
  
//链表的结构,给一个头指针保存链表第一个节点的地址
typedef struct SList{
	PNode pHead;//指向链表中的第一个节点
}SList,*PSList;

//链表的初始化
void SlistInit(SList* s){
	assert(s);
	s->pHead = NULL;
}

//创建新节点
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

//尾插
void SListPushBack(SList* s, SDataType data){
	assert(s);
	PNode pNewNode = BuySListNode(data);
	if (s->pHead==NULL){
		//空链表
		s->pHead=pNewNode;
	}
	else{
		//链表非空,找链表中最后一个节点
		PNode pCur = s->pHead;
		while (pCur->pNext){
			pCur = pCur->pNext;
		}
		PNode pNewNode = BuySListNode(data);
		pCur->pNext = pNewNode;
	}
}

//尾删
void SListPopBack(SList* s){
	assert(s);
	//空链表
	if (s->pHead==NULL){
		return;
	}
	//只有一个节点
	else if (s->pHead->pNext==NULL){
		free(s->pHead);
		s->pHead = NULL;
	}
	//两个或两个以上节点
	else{
		PNode pPre = NULL;//pPre保存最后一个节点的上一个节点
		PNode pCur = s->pHead;
		while (pCur->pNext)
		{
			pPre = pCur;
			pCur = pCur->pNext;
		}
		free(pCur);//释放最后一个节点空间
		pPre->pNext = NULL;//将前一个节点指向NULL
	}
}

//头插
void SListPushFront(SList* s,SDataType data){
	assert(s);
	PNode pNewNode = BuySListNode(data);
	pNewNode->pNext = s ->pHead;
	s->pHead = pNewNode;
}

//头删
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

//任意位置插入
void SListInsert(PNode pos, SDataType data){
	PNode pNewNode = NULL;
	if (pos==NULL){
		return;	
	}
	pNewNode = BuySListNode(data);
	pNewNode->pNext = pos->pNext;
	pos->pNext = pNewNode;
}

//任意位置删除
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

//查找链表中的元素
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

//获取有效元素个数
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

//检查链表是否为空
int SListEmpty(SList* s){
	assert(s);
	return s->pHead == NULL;
}

//清空有效节点
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

//销毁链表
void SListDestroy(SList* s){

}

//打印链表
void PrintSList(SList* s){
	assert(s);
	PNode pCur = s->pHead;
	while (pCur){
		printf("%d---->", pCur->data);
		pCur = pCur->pNext;
	}
	printf("NULL\n");
}

//测试
void TestSList(){
	SList s;

	//初始化测试
	SlistInit(&s);

	//尾插测试
	for (int i = 1; i < 6; ++i){
		SListPushBack(&s, i);
	}
	PrintSList(&s);

	//尾删测试
	SListPopBack(&s);
	PrintSList(&s);

	//头插测试
	SListPushFront(&s, 6);
	PrintSList(&s);

	//头删测试
	SListPopFront(&s);
	PrintSList(&s);

	//任意位置插入测试
	SListInsert(SListFind(&s,3),6 );
	PrintSList(&s);

	//任意位置删除测试
	SListErase(&s,SListFind(&s, 4));
	PrintSList(&s);
	
	//查找测试
	printf("%p\n", SListFind(&s, 1));

	//有效节点个数测试
	printf("%d\n",SListSize(&s));

	//判空测试
	printf("%d\n", SListEmpty(&s));

	//清空有效节点测试
	//SListClear(&s);
	//PrintSList(&s);

	//销毁链表测试
	//SListDestroy(&s);
}


int main(){
	TestSList();
	system("pause");
	return 0;
}
