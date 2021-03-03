#include "Sort.h"

//��ӡ����
void ShowArray(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//ѡ������
//ʱ�临�Ӷ�O(N^2)
void SelectSort(int *a, int n)
{
	assert(a);

	int start = 0;
	int end = n - 1;

	while (start < end)
	{
		int maxi, mini;
		maxi = mini = start;

		for (int i = start; i <= end; i++)
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

		Swap(&a[start], &a[mini]);

		if (maxi == start)
		{
			maxi = mini;
		}
		Swap(&a[end], &a[maxi]);

		start++;
		end--;
	}
}

//���µ����㷨
void AdjustDown(int* a, int n,int root)
{
	assert(a);

	int parent = root;
	int child = parent * 2 + 1;

	while (child < n)
	{
		if (child + 1 < n && a[child] < a[child + 1])
		{
			child++;
		}

		if (a[child] > a[parent])
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

//������
//ʱ�临�Ӷ�O(NlogN)
void HeapSort(int* a, int n)
{
	assert(a);

	//������Ҫ�����
	//ʱ�临�Ӷ�O(N)
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	//�����õĶѽ�������
	//ʱ�临�Ӷ�O(logN)
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}

//������������ܶԱ�
void TestOP()
{
	srand(time(0));
	const int N = 10000;

	int* a1 = (int*)malloc(sizeof(int)*N);
	int* a2 = (int*)malloc(sizeof(int)*N);

	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
	}

	int begin1 = clock();
	SelectSort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	HeapSort(a2, N);
	int end2 = clock();

	printf("SelectSort:%d\n", end1 - begin1);
	printf("HeapSort:%d\n", end2 - begin2);

	free(a1);
	free(a2);
}