#include <stdio.h>
#include <Windows.h>

void ShowArray(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//计数排序  
//时间复杂度O(N+range)
//空间复杂度O(range)
//只适用于整型，如果浮点数或者字符串排序，还得用比较排序
void CountSort(int *a, int n)
{
	//遍历数组，找出最大值与最小值
	int max = a[0];
	int min = a[0];

	for (int i = 1; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		if (a[i] < min)
		{
			min = a[i];
		}
	}

	//开辟range个临时空间
	int range = max - min + 1;
	int *tmp = (int *)calloc(sizeof(int), range);

	//统计原数组中每个数字出现的次数
	for (int i = 0; i < n; i++)
	{
		tmp[a[i] - min]++;
	}

	//进行排序
	int index = 0;
	for (int i = 0; i < range; i++)
	{
		while (tmp[i]--)
		{
			a[index++] = min + i;
		}
	}

	free(tmp);
}

//测试计数排序
void Test()
{
	int arr[] = { 1, 54, 47, 58, 9, 8, 6, 7, 4, 12, 23, 8, 9, 9, 7 };
	int size = sizeof(arr) / sizeof(arr[0]);

	ShowArray(arr, size);
	CountSort(arr, size);
	ShowArray(arr, size);
}

int main()
{
	Test();
	system("pause");
	return 0;
}