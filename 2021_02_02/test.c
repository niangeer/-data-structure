#include <stdio.h>
#include <Windows.h>

typedef struct Heap
{
	int* _a;
	int _size;
	int _capacity;
}Heap;

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//���µ����㷨��ǰ�᣺���������Ķ���С��
void AdistDown(int* a, int n, int root)
{
	int parent = root;
	//���ӽ���Ǹ��׽��Ķ���+1
	int child = parent * 2 + 1;
	while (child < n)
	{
		//�ҳ����Һ�����С����һ��
		if (child + 1 < n&&a[child + 1] < a[child])
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

void HeapInit(Heap* php, int *a, int n)
{
	php->_a = (int *)malloc(sizeof(int)*n);
	memcpy(php->_a, a, sizeof(int)*n);
	php->_size = php->_capacity = n;

	//������
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdistDown(php->_a, php->_size, i);
	}
}

int main()
{
	int a[] = { 27, 15, 18, 19, 28, 34, 65, 49, 25, 37 };
	Heap hp;
	HeapInit(&hp, a, sizeof(a) / sizeof(a[0]));
	system("pause");
	return 0;
}