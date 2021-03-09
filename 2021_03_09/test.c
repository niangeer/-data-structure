#include "MergeFile.h"

void ShowArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//���Կ�������
void QuickSortTest()
{
	int arr[] = { 2, 5, 4, 1, 3, 8, 6, 9, 7 };
	int size = sizeof(arr) / sizeof(arr[0]);

	ShowArray(arr, size);
	QuickSort(arr, 0, size - 1);
	ShowArray(arr, size);
}

//���Թ鲢�ļ�
void MergeFileTest()
{
	MergeFile("new.txt");
}

int main()
{
	QuickSortTest();
	MergeFileTest();

	system("pause");
	return 0;
}