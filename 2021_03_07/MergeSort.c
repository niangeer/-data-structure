#include "MergeSort.h"

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

void _MergeSort(int *a, int left, int right, int *tmp)
{
	assert(a);
	assert(tmp);

	if (left >= right)
		return;

	int mid = ((right - left) >> 1) + left;

	//[left,mid] [mid+1,right]
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);

	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;

	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[index++] = a[begin1++];
		}
		else
		{
			tmp[index++] = a[begin2++];
		}
	}

	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}

	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}

	//把归并好的在tmp的数据再拷回原数组
	for (int i = left; i <= right; i++)
	{
		a[i] = tmp[i];
	}
}

//归并排序递归版本
void MergeSort(int *a, int n)
{
	assert(a);

	int *tmp = (int*)malloc(sizeof(int)*n);
	if (NULL == tmp)
	{
		printf("malloc error\n");
		exit(-1);
	}

	_MergeSort(a, 0, n - 1, tmp);

	free(tmp);
}

void MergeArr(int *a, int begin1, int end1, int begin2, int end2, int *tmp)
{
	int left = begin1;
	int right = end2;
	int index = left;

	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[index++] = a[begin1++];
		}
		else
		{
			tmp[index++] = a[begin2++];
		}
	}

	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}

	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}

	for (int i = left; i <= right; i++)
	{
		a[i] = tmp[i];
	}
}

//归并排序非递归版本
void MergeSortNonR(int *a, int n)
{
	assert(a);

	int* tmp = (int*)malloc(sizeof(int)*n);
	if (NULL == tmp)
	{
		printf("malloc error\n");
		exit(-1);
	}

	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;

			//合并时只有第一组，第二组不存在就不需要合并
			if (begin2 >= n)
			{
				break;
			}

			//合并时第二组只有部分数据，需要修正end2边界
			if (end2 >= n)
			{
				end2 = n - 1;
			}

			MergeArr(a, begin1, end1, begin2, end2, tmp);
		}
		gap *= 2;
	}

	free(tmp);
}