#include "Stack.h"

void Swap(int *p1, int *p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//前后指针法
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

//快速排序非递归版本
//递归改非递归--1，改循环（简单版本才能改循环，例斐波那契数列）2，栈模拟存储数据非递归
//非递归：1，提高效率（建栈有消耗）
//        2，递归的缺陷为若栈帧的深度太深，会造成栈溢出，系统的栈空间为M级别,堆为G级别
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