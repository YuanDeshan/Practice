//小堆向下调整
void AdjustDown(int *array, int size,int parent)//size表示总结点个数，parent表示要调整的节点
{
	//定义一个孩子，默认是左孩子
	int child=0;
	//如果左孩子小于节点个数说明没有调整到最后一层
	while (child<size)
	{
		//1.找到parent的最小孩子
		child = (parent << 1 )+ 1;//左孩子位置
		//child+1<size:表示有右孩子
		//如果右孩子比左孩子小，用左孩子标记右孩子
		if (child + 1 < size&&array[child + 1] < array[child])
		{
			child = child + 1;
		}
		//2.如果双亲比最小孩子还要大，则交换，并更新双亲与孩子位置
		if (array[parent] > array[child])
		{
			std::swap(array[parent], array[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		//如果双亲比最小孩子还要小，则返回
		else
		{
			return;
		}
	}
}