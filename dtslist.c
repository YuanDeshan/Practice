#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdlib.h>

//��̬��˳���
typedef int DataType;
typedef struct SeqList{
	DataType* array;//����һ������ָ�����
	int capacity;//˳�����ܴ�С
	int size;//˳�������ЧԪ�صĸ���
}SeqList, *PSeq;

//˳����ʼ��
void SeqListInit(PSeq ps,int capacity){
	ps->array = (DataType*)malloc(sizeof(DataType)*capacity);
	if (ps->array == NULL){
		assert(0);
		return;
	}
	ps->capacity = capacity;
	ps->size = 0
}

//˳���β��
void SeqListPushBack(PSeq ps, DataType data){
	assert(ps);	
	//˳�����

	ps->array[ps->size] = data;
	ps->size++;
}

//˳���βɾ
int SeqListEmpty(PSeq ps);
void SeqListPopBack(PSeq ps){
	assert(ps);
	if (SeqListEmpty(ps)){
		return;
	}
	ps->size--;
}

//˳���ͷ��
void SeqListPushFront(PSeq ps, DataType data){
	assert(ps);
	//CheckCapacity(ps);
	//��˳���������Ԫ��ͳһ������һ��λ��
	for (int i = ps->size - 1; i >= 0; i--){
		ps->array[i + 1] = ps->array[i];
	}
	//����Ԫ��
	ps->array[0] = data;
	++ps->size;
}

//˳���ͷɾ
void SeqListPopFront(PSeq ps){
	assert(ps);
	if (SeqListEmpty(ps)){
		return;
	}
	//��˳�����Ԫ������ǰ��һ��λ��
	for (int i = 1; i < ps->size; ++i){
		ps->array[i - 1] = ps->array[i];
	}
	ps->size--;
}

//˳���ָ��λ�ò�������
void SeqListInsert(PSeq ps, int pos, DataType data){
	assert(ps);
	//����λ�ò������Ϸ��ж�
	if (pos<0 || pos>ps->size){
		return;
	}
	//CheckCapacity
	for (int i = ps->size - 1; i >= pos-1; i--){
		ps->array[i + 1] = ps->array[i];
	}
	ps->array[pos-1] = data;
	ps->size++;
}

//˳���ָ��λ��ɾ������
void SeqListErase(PSeq ps, int pos){
	assert(ps);
	//����λ�ò������Ϸ��ж�
	if (pos < 0 || pos >= ps->size){
		return;
	}
	for (int i = pos; i < ps->size; ++i){
		ps->array[i - 1] = ps->array[i];
	}
	ps->size--;
}

//Ѱ��˳�����ָ������
int SeqListFind(PSeq ps, DataType data){
	assert(ps);
	for (int i = 0; i < ps->size; ++i){
		if (ps->array[i] == data){
			return i;
		}
	}
	return -1;
}

//����˳�������ЧԪ�صĸ���
int SeqListSize(PSeq ps){
	assert(ps);
	return ps->size;
}

//����˳���Ŀռ��С
int SeqListCapacity(PSeq ps){
	assert(ps);
	return ps->capacity;
}

//���˳���
void SeqListClear(PSeq ps){
	assert(ps);
	ps->size = 0;
}

//˳���Ϊ���ж�
int SeqListEmpty(PSeq ps){
	assert(ps);
	return 0 == ps->size;
}


//ɾ��˳����е�һ��Ϊdata��Ԫ��
void SeqListRemove(PSeq ps, DataType data){
	SeqListErase(ps, SeqListFind(ps, data+1));
}


//˳�������
void SeqListCheckCapacity(PSeq ps){
	assert(ps);
	if (ps->size == ps->capacity){
		int newCapacity = ps->capacity * 2;
		//�����¿ռ�
		int* pTemp = (DataType*)malloc(newCapacity*(newCapacity*sizeof(DataType)));
		if (pTemp == NULL){
			assert(0);
			return;
		}//����Ԫ��
		for (int i = 0; i < ps->size; ++i){
			pTemp[i] = ps->array[i];
			//�ͷžɿռ�
			free(ps->array);
			//���²���
			ps->array = pTemp;
			ps->capacity = newCapacity;
		}
	}
}

//����˳���
void SeqListDestory(SeqList* ps){
	if (ps->array){
		free(ps->array);
		ps->array=0;
		ps->capacity = 0;
		ps->size=0;
	}
}

//˳����ӡ
void SeqListPrint(PSeq ps){
	printf("SeqList: ");
	for (int i = 0; i < ps->size; ++i){
		printf("%d\t", ps->array[i]);
	}
	putchar('\n');
}

//˳������
void TestSeqList(){
	int pos, n;
	SeqList s;

	//��ʼ������
	SeqListInit(&s, 1024);

	//β�����
	for (int i = 1; i < 11; ++i){
		SeqListPushBack(&s, i);
	}
	SeqListPrint(&s);

	//βɾ����
	SeqListPopBack(&s);
	SeqListPrint(&s);

	//ͷ�����
	SeqListPushFront(&s, 0);
	SeqListPrint(&s);

	//ͷɾ����
	SeqListPopFront(&s);
	SeqListPrint(&s);

	//ָ���������
	printf("������Ҫ˳����н�Ҫ�����λ���Լ�����:\n");
	scanf("%d%d", &pos, &n);
	SeqListInsert(&s, pos, n);
	SeqListPrint(&s);

	//ָ��λ��ɾ������
	printf("������˳���Ҫɾ���е�λ��:\n");
	scanf("%d", &pos);
	SeqListErase(&s, pos);
	SeqListPrint(&s);

	//ָ������Ѱ�Ҳ���
	printf("������Ҫ���ҵ�����:\n");
	scanf("%d", &n);
	SeqListFind(&s, n);
	printf("%d\n", SeqListFind(&s, n));

	//������ЧԪ�ظ�������
	printf("��˳�����ЧԪ�ظ���Ϊ:%d\n", SeqListSize(&s));

	//����˳���ռ��С
	printf("��˳���Ŀռ��СΪ:%d\n", SeqListCapacity(&s));


	//���˳������
	//SeqListClear(&s);
	//SeqListPrint(&s);

	//ɾ��˳����е�һ��Ϊdata��Ԫ��
	printf("������Ҫɾ��Ԫ��(��Ϊ��һ��):\n");
	scanf("%d", &n);
	SeqListRemove(&s, n);
	SeqListPrint(&s);

	//˳������ݲ���
	//SeqListCheckCapacity(&s);
	//printf("%d\n", SeqListCapacity(&s));

	//����˳������
	SeqListDestory(&s);
	SeqListPrint(&s);
}
int main(){
	TestSeqList();
	system("pause");
	return 0;
	}