#include "Stack.h"

void Swap(int *p1, int *p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//ǰ��ָ�뷨
int PartSort(int *a, int start, int end)
{
	assert(a);

	int keyIndex = end;
	int cur = start;
	int prev = cur - 1;

	while (cur <= end)
	{
		if (a[cur] <= a[keyIndex] && ++prev != cur)
		{
			Swap(&a[cur], &a[prev]);
		}

		cur++;
	}

	return prev;
}

//��������ǵݹ�汾
//�ݹ�ķǵݹ�--1����ѭ�����򵥰汾���ܸ�ѭ������쳲��������У�2��ջģ��洢���ݷǵݹ�
//�ǵݹ飺1�����Ч�ʣ���ջ�����ģ�
//        2���ݹ��ȱ��Ϊ��ջ֡�����̫������ջ�����ϵͳ��ջ�ռ�ΪM����,��ΪG����
void QuickSortNonR(int* a, int left, int right)
{
	assert(a);

	Stack st;
	StackInit(&st);

	StackPush(&st, right);
	StackPush(&st, left);

	while (!StackEmpty(&st))
	{
		int left = StackTop(&st);
		StackPop(&st);
		int right = StackTop(&st);
		StackPop(&st);

		int div = PartSort(a, left, right);
		//[left,div-1] div [div+1,right]

		if (div + 1 < right)
		{
			StackPush(&st, right);
			StackPush(&st, div + 1);
		}

		if (left < div - 1)
		{
			StackPush(&st, div - 1);
			StackPush(&st, left);
		}
	}

	StackDestory(&st);
}