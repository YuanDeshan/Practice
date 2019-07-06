#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdlib.h>

//动态的顺序表
typedef int DataType;
typedef struct SeqList{
	DataType* array;//定义一个整形指针变量
	int capacity;//顺序表的总大小
	int size;//顺序表中有效元素的个数
}SeqList, *PSeq;

//顺序表初始化
void SeqListInit(PSeq ps,int capacity){
	ps->array = (DataType*)malloc(sizeof(DataType)*capacity);
	if (ps->array == NULL){
		assert(0);
		return;
	}
	ps->capacity = capacity;
	ps->size = 0
}

//顺序表尾插
void SeqListPushBack(PSeq ps, DataType data){
	assert(ps);	
	//顺序表满

	ps->array[ps->size] = data;
	ps->size++;
}

//顺序表尾删
int SeqListEmpty(PSeq ps);
void SeqListPopBack(PSeq ps){
	assert(ps);
	if (SeqListEmpty(ps)){
		return;
	}
	ps->size--;
}

//顺序表头插
void SeqListPushFront(PSeq ps, DataType data){
	assert(ps);
	//CheckCapacity(ps);
	//将顺序表中所有元素统一向后搬移一个位置
	for (int i = ps->size - 1; i >= 0; i--){
		ps->array[i + 1] = ps->array[i];
	}
	//插入元素
	ps->array[0] = data;
	++ps->size;
}

//顺序表头删
void SeqListPopFront(PSeq ps){
	assert(ps);
	if (SeqListEmpty(ps)){
		return;
	}
	//将顺序表中元素整体前移一个位置
	for (int i = 1; i < ps->size; ++i){
		ps->array[i - 1] = ps->array[i];
	}
	ps->size--;
}

//顺序表指定位置插入数据
void SeqListInsert(PSeq ps, int pos, DataType data){
	assert(ps);
	//传入位置参数不合法判定
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

//顺序表指定位置删除数据
void SeqListErase(PSeq ps, int pos){
	assert(ps);
	//传入位置参数不合法判定
	if (pos < 0 || pos >= ps->size){
		return;
	}
	for (int i = pos; i < ps->size; ++i){
		ps->array[i - 1] = ps->array[i];
	}
	ps->size--;
}

//寻找顺序表中指定数据
int SeqListFind(PSeq ps, DataType data){
	assert(ps);
	for (int i = 0; i < ps->size; ++i){
		if (ps->array[i] == data){
			return i;
		}
	}
	return -1;
}

//返回顺序表中有效元素的个数
int SeqListSize(PSeq ps){
	assert(ps);
	return ps->size;
}

//返回顺序表的空间大小
int SeqListCapacity(PSeq ps){
	assert(ps);
	return ps->capacity;
}

//清空顺序表
void SeqListClear(PSeq ps){
	assert(ps);
	ps->size = 0;
}

//顺序表为空判定
int SeqListEmpty(PSeq ps){
	assert(ps);
	return 0 == ps->size;
}


//删除顺序表中第一个为data的元素
void SeqListRemove(PSeq ps, DataType data){
	SeqListErase(ps, SeqListFind(ps, data+1));
}


//顺序表扩容
void SeqListCheckCapacity(PSeq ps){
	assert(ps);
	if (ps->size == ps->capacity){
		int newCapacity = ps->capacity * 2;
		//申请新空间
		int* pTemp = (DataType*)malloc(newCapacity*(newCapacity*sizeof(DataType)));
		if (pTemp == NULL){
			assert(0);
			return;
		}//拷贝元素
		for (int i = 0; i < ps->size; ++i){
			pTemp[i] = ps->array[i];
			//释放旧空间
			free(ps->array);
			//更新参数
			ps->array = pTemp;
			ps->capacity = newCapacity;
		}
	}
}

//销毁顺序表
void SeqListDestory(SeqList* ps){
	if (ps->array){
		free(ps->array);
		ps->array=0;
		ps->capacity = 0;
		ps->size=0;
	}
}

//顺序表打印
void SeqListPrint(PSeq ps){
	printf("SeqList: ");
	for (int i = 0; i < ps->size; ++i){
		printf("%d\t", ps->array[i]);
	}
	putchar('\n');
}

//顺序表测试
void TestSeqList(){
	int pos, n;
	SeqList s;

	//初始化测试
	SeqListInit(&s, 1024);

	//尾插测试
	for (int i = 1; i < 11; ++i){
		SeqListPushBack(&s, i);
	}
	SeqListPrint(&s);

	//尾删测试
	SeqListPopBack(&s);
	SeqListPrint(&s);

	//头插测试
	SeqListPushFront(&s, 0);
	SeqListPrint(&s);

	//头删测试
	SeqListPopFront(&s);
	SeqListPrint(&s);

	//指定插入测试
	printf("请输入要顺序表中将要插入的位置以及数字:\n");
	scanf("%d%d", &pos, &n);
	SeqListInsert(&s, pos, n);
	SeqListPrint(&s);

	//指定位置删除测试
	printf("请输入顺序表将要删除中的位置:\n");
	scanf("%d", &pos);
	SeqListErase(&s, pos);
	SeqListPrint(&s);

	//指定数据寻找测试
	printf("请输入要查找的数据:\n");
	scanf("%d", &n);
	SeqListFind(&s, n);
	printf("%d\n", SeqListFind(&s, n));

	//返回有效元素个数测试
	printf("该顺序表有效元素个数为:%d\n", SeqListSize(&s));

	//返回顺序表空间大小
	printf("该顺序表的空间大小为:%d\n", SeqListCapacity(&s));


	//清空顺序表测试
	//SeqListClear(&s);
	//SeqListPrint(&s);

	//删除顺序表中第一个为data的元素
	printf("请输入要删掉元素(仅为第一个):\n");
	scanf("%d", &n);
	SeqListRemove(&s, n);
	SeqListPrint(&s);

	//顺序表扩容测试
	//SeqListCheckCapacity(&s);
	//printf("%d\n", SeqListCapacity(&s));

	//销毁顺序表测试
	SeqListDestory(&s);
	SeqListPrint(&s);
}
int main(){
	TestSeqList();
	system("pause");
	return 0;
	}