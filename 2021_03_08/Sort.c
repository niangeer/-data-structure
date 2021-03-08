#include "Sort.h"
#include "Stack.h"

//��ӡ����
void ShowArray(int* a, int n)
{
	assert(a);

	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//��ͨ��������
//ʱ�临�Ӷ�O(N^2)  �ռ临�Ӷ�O(1)
void InsertSort(int* a, int n)
{
	assert(a);

	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			//��end + 1�����ݲ��뵽[0,end]����������
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

//ϣ������ ʱ�临�Ӷ�O(N^1.3-N^2)
void ShellSort(int* a, int n)
{
	assert(a);

	//1��gap > 1�൱��Ԥ����������ӽ�����
	//2��gap == 1�൱��ֱ�Ӳ������򣬱�֤����
	int gap = n;

	//nΪ1ʱ��һ��������Ҫ����
	while (gap > 1)
	{
		//��֤���һ��gapһ������1
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

//ѡ������  ʱ�临�Ӷ�O(N^2)
void SelectSort(int* a, int n)
{
	assert(a);
	int left = 0;
	int right = n - 1;
	while (left < right)
	{
		//��[left,right]֮���ҳ���С������������±�
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

		//��maxi��left��λ���ص�����maxi��λ����Ҫ����
		if (maxi == left)
		{
			maxi = mini;
		}
		Swap(&a[right], &a[maxi]);

		left++;
		right--;
	}
}

//���µ����㷨
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

//������  ʱ�临�Ӷ�O(N*logN)
void HeapSort(int* a, int n)
{
	assert(a);

	//����  ʱ�临�Ӷ�O(N)
	//����������
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

//ð������  ʱ�临�Ӷ�O(N^2)
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

//����ȡ��
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

//����ָ�뷨
int PartSort1(int *a, int left, int right)
{
	assert(a);

	int midIndex = GetMidIndex(a, left, right);
	Swap(&a[midIndex], &a[right]);

	int keyIndex = right;
	while (left < right)
	{
		//leftҪȥ�Ҵ�
		while (left < right && a[left] <= a[keyIndex])
		{
			left++;
		}

		//rightҪȥ��С
		while (left < right && a[right] >= a[keyIndex])
		{
			right--;
		}
		Swap(&a[left], &a[right]);
	}
	Swap(&a[right], &a[keyIndex]);

	return right;
}

//�ڿӷ�
int PartSort2(int *a, int left, int right)
{
	assert(a);

	int midIndex = GetMidIndex(a, left, right);
	Swap(&a[midIndex], &a[right]);

	//�� ������ζ�����ڵ�λ�ÿɱ����ǣ�
	int key = a[right];
	while (left < right)
	{
		while (left < right && a[left] <= key)
		{
			left++;
		}
		//����ҵ���key���ֵ��ұߣ�left��λ���γ��µĿ�
		a[right] = a[left];

		while (left < right && a[right] >= key)
		{
			right--;
		}
		//�ұ��ҵ���keyС��ֵ���ߣ�right��λ���γ��µĿ�
		a[left] = a[right];
	}
	a[right] = key;

	return right;
}

//ǰ��ָ�뷨
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

//��������ݹ�汾  ʱ�临�Ӷ�O(N*logN)���ռ临�Ӷ�O(logN)
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

//�鲢�����Ӻ���
void _MergeSort(int* a, int left, int right, int* tmp)
{
	assert(a);

	if (left >= right)
		return;

	int mid = ((right - left) >> 1) + left;

	//[left,mid] [mid+1,right]��������Ժϲ�����������
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);

	//�鲢ʹ[left,mid][mid+1,right]����
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

//�鲢����ݹ�汾
//ʱ�临�Ӷ�O(NlogN),�ռ临�Ӷ�O(N)
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


//�鲢����ǵݹ�汾�Ӻ���
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

//�鲢����ǵݹ�汾
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

			//�ϲ�ʱֻ�е�һ�飬�ڶ��鲻���ڣ�����Ҫ�ϲ�
			if (begin2 >= n)
			{
				break;
			}
			//�ϲ�ʱ�ڶ���ֻ�в������ݣ���Ҫ����end2�߽�
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