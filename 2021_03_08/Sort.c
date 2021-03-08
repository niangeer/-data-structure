#include "Sort.h"
#include "Stack.h"

//打印数组
void ShowArray(int* a, int n)
{
	assert(a);

	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//普通插入排序
//时间复杂度O(N^2)  空间复杂度O(1)
void InsertSort(int* a, int n)
{
	assert(a);

	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			//把end + 1的数据插入到[0,end]的有序区间
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

//希尔排序 时间复杂度O(N^1.3-N^2)
void ShellSort(int* a, int n)
{
	assert(a);

	//1，gap > 1相当于预排序，让数组接近有序
	//2，gap == 1相当于直接插入排序，保证有序
	int gap = n;

	//n为1时，一个数不需要排序
	while (gap > 1)
	{
		//保证最后一次gap一定等于1
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}

void Swap(int *p1, int *p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//选择排序  时间复杂度O(N^2)
void SelectSort(int* a, int n)
{
	assert(a);
	int left = 0;
	int right = n - 1;
	while (left < right)
	{
		//在[left,right]之间找出最小数与最大数的下标
		int maxi, mini;
		maxi = mini = left;
		for (int i = left + 1; i <= right; i++)
		{
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
			if (a[i] < a[mini])
			{
				mini = i;
			}
		}
		Swap(&a[left], &a[mini]);

		//若maxi与left的位置重叠，则maxi的位置需要修正
		if (maxi == left)
		{
			maxi = mini;
		}
		Swap(&a[right], &a[maxi]);

		left++;
		right--;
	}
}

//向下调整算法
void AdjustDown(int* a, int n, int root)
{
	assert(a);

	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			child++;
		}

		if (a[child]>a[parent])
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

//堆排序  时间复杂度O(N*logN)
void HeapSort(int* a, int n)
{
	assert(a);

	//建堆  时间复杂度O(N)
	//排升序建造大堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);

		end--;
	}
}

//冒泡排序  时间复杂度O(N^2)
void BubbleSort(int* a, int n)
{
	assert(a);

	int end = n - 1;
	while (end > 0)
	{
		int exchange = 0;
		for (int i = 0; i < end; i++)
		{
			if (a[i]>a[i + 1])
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

//三数取中
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
	else   //a[left] >= a[mid]
	{
		if (a[mid] > a[right])
			return mid;
		else if (a[left] < a[right])
			return left;
		else
			return right;
	}
}

//左右指针法
int PartSort1(int *a, int left, int right)
{
	assert(a);

	int midIndex = GetMidIndex(a, left, right);
	Swap(&a[midIndex], &a[right]);

	int keyIndex = right;
	while (left < right)
	{
		//left要去找大
		while (left < right && a[left] <= a[keyIndex])
		{
			left++;
		}

		//right要去找小
		while (left < right && a[right] >= a[keyIndex])
		{
			right--;
		}
		Swap(&a[left], &a[right]);
	}
	Swap(&a[right], &a[keyIndex]);

	return right;
}

//挖坑法
int PartSort2(int *a, int left, int right)
{
	assert(a);

	int midIndex = GetMidIndex(a, left, right);
	Swap(&a[midIndex], &a[right]);

	//坑 （坑意味着它在的位置可被覆盖）
	int key = a[right];
	while (left < right)
	{
		while (left < right && a[left] <= key)
		{
			left++;
		}
		//左边找到比key大的值填到右边，left的位置形成新的坑
		a[right] = a[left];

		while (left < right && a[right] >= key)
		{
			right--;
		}
		//右边找到比key小的值填到左边，right的位置形成新的坑
		a[left] = a[right];
	}
	a[right] = key;

	return right;
}

//前后指针法
int PartSort3(int* a, int left, int right)
{
	assert(a);

	int midIndex = GetMidIndex(a, left, right);
	Swap(&a[midIndex], &a[right]);

	int key = a[right];

	int cur = left;
	int prev = left - 1;
	while (cur <= right)
	{
		if (a[cur] <= key && ++prev != cur)
		{
			Swap(&a[prev], &a[cur]);
		}
		cur++;
	}

	return prev;
}

//快速排序递归版本  时间复杂度O(N*logN)，空间复杂度O(logN)
void QuickSort(int* a, int left, int right)
{
	assert(a);

	if (left >= right)
		return;

	int div = PartSort3(a, left, right);
	//[left,div-1] div [div+1,right]
	QuickSort(a, left, div - 1);
	QuickSort(a, div + 1, right);
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
		int begin = StackTop(&st);
		StackPop(&st);
		int end = StackTop(&st);
		StackPop(&st);

		int div = PartSort1(a, begin, end);

		//[begin,div-1] div [div+1,end]
		if (div + 1 < end)
		{
			StackPush(&st, end);
			StackPush(&st, div + 1);
		}

		if (begin < div - 1)
		{
			StackPush(&st, div - 1);
			StackPush(&st, begin);
		}
	}

	StackDestory(&st);
}

//归并排序子函数
void _MergeSort(int* a, int left, int right, int* tmp)
{
	assert(a);

	if (left >= right)
		return;

	int mid = ((right - left) >> 1) + left;

	//[left,mid] [mid+1,right]有序，则可以合并，现在无序
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);

	//归并使[left,mid][mid+1,right]有序；
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[index] = a[begin1];
			index++;
			begin1++;
		}
		else
		{
			tmp[index] = a[begin2];
			index++;
			begin2++;
		}
	}

	while (begin1 <= end1)
	{
		tmp[index] = a[begin1];
		index++;
		begin1++;
	}

	while (begin2 <= end2)
	{
		tmp[index] = a[begin2];
		index++;
		begin2++;
	}

	for (int i = left; i <= right; i++)
	{
		a[i] = tmp[i];
	}
}

//归并排序递归版本
//时间复杂度O(NlogN),空间复杂度O(N)
void MergeSort(int* a, int n)
{
	assert(a);

	int *tmp = (int*)malloc(sizeof(int)*n);
	if (NULL == tmp)
	{
		exit(-1);
	}

	_MergeSort(a, 0, n - 1, tmp);

	free(tmp);
}


//归并排序非递归版本子函数
void _MergeArr(int* a, int begin1, int end1, int begin2, int end2, int *tmp)
{
	assert(a);
	assert(tmp);

	int left = begin1;
	int right = end2;
	int index = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[index] = a[begin1];
			index++;
			begin1++;
		}
		else
		{
			tmp[index] = a[begin2];
			index++;
			begin2++;
		}
	}

	while (begin1 <= end1)
	{
		tmp[index] = a[begin1];
		index++;
		begin1++;
	}

	while (begin2 <= end2)
	{
		tmp[index] = a[begin2];
		index++;
		begin2++;
	}

	for (int i = left; i <= right; i++)
	{
		a[i] = tmp[i];
	}
}

//归并排序非递归版本
void MergeSortNonR(int* a, int n)
{
	assert(a);

	int *tmp = (int*)malloc(sizeof(int)*n);
	if (NULL == tmp)
	{
		exit(-1);
	}

	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2*gap)
		{
			//[i,i+gap-1] [i+gap,i+2*gap-1]
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;

			//合并时只有第一组，第二组不存在，则不需要合并
			if (begin2 >= n)
			{
				break;
			}
			//合并时第二组只有部分数据，需要修正end2边界
			if (end2 >= n)
			{
				end2 = n - 1;
			}
			_MergeArr(a, begin1, end1, begin2, end2, tmp);
		}
		gap *= 2;
	}

	free(tmp);
}