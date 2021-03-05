#include "QuickSort.h"

//打印数组
void ShowArray(int *a, int n)
{
	assert(a);

	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void Swap(int *p1, int *p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

int GetMidIndex(int *a, int left, int right)
{
	assert(a);

	int mid = ((right - left) >> 1) + left;

	if (a[mid] > a[left])
	{
		if (a[mid] < a[right])
			return mid;
		else if (a[left]>a[right])
			return left;
		else
			return right;
	}
	else   //a[mid] <= a[left]
	{
		if (a[mid] > a[right])
			return mid;
		else if (a[right] > a[left])
			return left;
		else
			return right;
	}
}

//左右指针法
int PartSort1(int *a, int start, int end)
{
	assert(a);

	int midIndex = GetMidIndex(a, start, end);
	Swap(&a[midIndex], &a[end]);

	int keyIndex = end;

	while (start < end)
	{
		//找大
		while (start < end && a[start] <= a[keyIndex])
		{
			start++;
		}

		//找大
		while (start < end && a[end] >= a[keyIndex])
		{
			end--;
		}
		Swap(&a[start], &a[end]);
	}

	Swap(&a[end], &a[keyIndex]);

	return end;
}

int PartSort2(int* a, int start, int end)
{
	assert(a);

	int midIndex = GetMidIndex(a, start, end);
	Swap(&a[midIndex], &a[end]);

	//创建坑（坑的意思是它可被覆盖）
	int key = a[end];

	while (start < end)
	{
		while (start < end && a[start] <= key)
		{
			start++;
		}

		//左边找到比key大的填到右边的坑，start位置形成新的坑
		a[end] = a[start];

		while (start < end && a[end] >= key)
		{
			end--;
		}

		//右边找到比key小的填到左边的坑，end位置形成新的坑
		a[start] = a[end];
	}
	a[end] = key;

	return end;
}

//前后指针法
int PartSort3(int *a, int start, int end)
{
	assert(a);

	int midIndex = GetMidIndex(a, start, end);
	Swap(&a[midIndex], &a[end]);

	int prev = start - 1;
	int cur = start;
	int keyIndex = end;

	while (cur < end)
	{
		if (a[cur] < a[keyIndex] && prev != cur)
		{
			prev++;
			Swap(&a[prev], &a[cur]);
		}

		cur++;
	}

	prev++;
	Swap(&a[prev], &a[keyIndex]);

	return prev;
}

//快速排序
void QuickSort(int *a, int left, int right)
{
	assert(a);

	if (left >= right)
		return;

	int div = PartSort3(a, left, right);
	QuickSort(a, left, div - 1);
	QuickSort(a, div + 1, right);
}