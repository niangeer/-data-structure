#include "heap.h"

 static void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//ǰ�᣺������������С��
static void AdjustDown(HPDataType* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;  //����

	while (child < n)
	{
		//�ҳ����Һ�����С����һ��
		if (child + 1 < n && a[child + 1] < a[child])
		{
			child++;
		}
		//�������С�ڸ����򽻻�
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

static void AdjustUp(HPDataType* a, int n, int child)
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

void HeapInit(heap* php, int *a, int n)
{
	assert(php);

	php->_a = (HPDataType*)malloc(sizeof(HPDataType)*n);
	memcpy(php->_a, a, sizeof(HPDataType)*n);
	php->_capacity = php->_size = n;

	//������
	for (int i = (n - 1 - 1) / 2; 0 <= i; i--)
	{
		AdjustDown(php->_a, php->_size, i);
	}
}

//������
void HeapDestory(heap* php)
{
	assert(php);

	free(php->_a);
	php->_a = NULL;
	php->_capacity = php->_size = 0;
}

//�Ѳ���
void HeapPush(heap* php, HPDataType x)
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

	AdjustUp(php->_a, php->_size,php->_size-1);
}

//��ɾ��
void HeapPop(heap* php)
{
	assert(php);
	assert(php->_size > 0);

	Swap(&php->_a[0], &php->_a[php->_size - 1]);
	php->_size--;

	AdjustDown(php->_a, php->_size, 0);
}

//��ȡ�Ѷ�����
HPDataType HeapTop(heap* php)
{
	assert(php);
	assert(php->_size > 0);

	return php->_a[0];
}
