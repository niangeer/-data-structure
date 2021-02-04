#include "Heap.h"

void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//向下调整算法
//前提：左右子树都是小堆或者大堆
static void AdjustDown(HPDataType* a,int n,int root)
{
	int parent = root;
	int child = parent * 2 + 1;  //左孩子

	while (child < n)
	{
		//找出左右孩子中小的那个
		if (child + 1 < n&&a[child + 1] < a[child])
		{
			child++;
		}
		//孩子小于父亲则交换
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}

		else
		{
			break;
		}
	}
}

//堆的初始化
void AdjustUp(HPDataType* a, int n, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void HeapInit(Heap* php, HPDataType* a, int n)
{
	assert(php);
	//成员初始化
	php->_a = (HPDataType*)malloc(sizeof(HPDataType)*n);
	if (NULL == php->_a)
	{
		exit(-1);
	}
	memcpy(php->_a, a, sizeof(HPDataType)*n);
	php->_capacity = n;
	php->_size = n;

	//建堆
	for (int i = (n - 1 - 1) / 2; 0 <= i; i--)
	{
		AdjustDown(php->_a, php->_size, i);
	}
}

//堆的销毁
void HeapDestory(Heap* php)
{
	assert(php);

	free(php->_a);
	php->_a = NULL;
	php->_capacity = 0;
	php->_size = 0;
}

//堆的插入
void HeapPush(Heap* php, HPDataType x)
{
	assert(php);

	if (php->_capacity == php->_size)
	{
		HPDataType* tmp = (HPDataType*)realloc(php->_a, sizeof(HPDataType)*php->_capacity * 2);
		if (NULL == tmp)
		{
			exit(-1);
		}
		php->_a = tmp;
		php->_capacity *= 2;
	}
	php->_a[php->_size] = x;
	php->_size++;

	AdjustUp(php->_a, php->_size, php->_size - 1);
}

//堆的删除
void HeapPop(Heap* php)
{
	assert(php);
	assert(php->_size > 0);

	Swap(&php->_a[0], &php->_a[php->_size - 1]);
	php->_size--;
	AdjustDown(php->_a, php->_size, 0);
}

//获取堆顶的数据
HPDataType HeapTop(Heap* php)
{
	assert(php);
	assert(php->_size > 0);

	return php->_a[0];
}

//堆的排序
void HeapSort(Heap* php)
{
	assert(php);

	for (int i = php->_size - 1; i > 0; i--)
	{
		Swap(&php->_a[i], &php->_a[0]);
		AdjustDown(php->_a, i, 0);
	}
}