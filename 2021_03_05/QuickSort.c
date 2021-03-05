#include "QuickSort.h"

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

//����ָ�뷨
int PartSort1(int *a, int start, int end)
{
	assert(a);

	int midIndex = GetMidIndex(a, start, end);
	Swap(&a[midIndex], &a[end]);

	int keyIndex = end;

	while (start < end)
	{
		//�Ҵ�
		while (start < end && a[start] <= a[keyIndex])
		{
			start++;
		}

		//�Ҵ�
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

	//�����ӣ��ӵ���˼�����ɱ����ǣ�
	int key = a[end];

	while (start < end)
	{
		while (start < end && a[start] <= key)
		{
			start++;
		}

		//����ҵ���key�����ұߵĿӣ�startλ���γ��µĿ�
		a[end] = a[start];

		while (start < end && a[end] >= key)
		{
			end--;
		}

		//�ұ��ҵ���keyС�����ߵĿӣ�endλ���γ��µĿ�
		a[start] = a[end];
	}
	a[end] = key;

	return end;
}

//ǰ��ָ�뷨
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

//��������
void QuickSort(int *a, int left, int right)
{
	assert(a);

	if (left >= right)
		return;

	int div = PartSort3(a, left, right);
	QuickSort(a, left, div - 1);
	QuickSort(a, div + 1, right);
}