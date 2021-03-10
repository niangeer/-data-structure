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

//��������  
//ʱ�临�Ӷ�O(N+range)
//�ռ临�Ӷ�O(range)
//ֻ���������ͣ���������������ַ������򣬻����ñȽ�����
void CountSort(int *a, int n)
{
	//�������飬�ҳ����ֵ����Сֵ
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

	//����range����ʱ�ռ�
	int range = max - min + 1;
	int *tmp = (int *)calloc(sizeof(int), range);

	//ͳ��ԭ������ÿ�����ֳ��ֵĴ���
	for (int i = 0; i < n; i++)
	{
		tmp[a[i] - min]++;
	}

	//��������
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

//���Լ�������
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