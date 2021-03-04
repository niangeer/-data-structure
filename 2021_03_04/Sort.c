#include "Sort.h"

//��ӡ����
void ShowArray(int *a, int n)
{
	assert(a);

	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void Swap(int *p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//ð������
//ʱ�临�Ӷ�O(N^2)
void BubbleSort(int *a, int n)
{
	assert(a);

	int end = n - 1;
	while (end > 0)
	{
		int exchange = 0;
		for (int i = 0; i < end; i++)
		{
			if (a[i] > a[i + 1])
			{
				Swap(&a[i], &a[i + 1]);
				exchange = 1;
			}
		}

		if (0 == exchange)
		{
			break;
		}

		end--;
	}
}

//����ȡ��
int GetMidIndex(int* a, int left, int right)
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
	else    //a[mid]<=a[left]
	{
		if (a[mid] > a[right])
			return mid;

		else if (a[right] > a[left])
			return left;

		else
			return right;
	}
}

//���˿���(����ָ�뷨)
int PartSort(int *a, int start, int end)
{
	assert(a);

	int midIndex = GetMidIndex(a, start, end);
	Swap(&a[midIndex], &a[end]);

	int keyIndex = end;

	while (start < end)
	{
		//start�Ҵ�
		while (start < end && a[start] <= a[keyIndex])
		{
			start++;
		}

		//end��С
		while (start < end && a[end] >= a[keyIndex])
		{
			end--;
		}
		Swap(&a[start], &a[end]);
	}

	Swap(&a[end], &a[keyIndex]);

	return end;
}

//����
//ʱ�临�Ӷ�O(NlogN)
void QuickSort(int *a, int left, int right)
{
	assert(a);

	if (left >= right)
		return;

	int div = PartSort(a, left, right);
	QuickSort(a, left, div - 1);
	QuickSort(a, div + 1, right);
}