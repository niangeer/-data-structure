#include "MergeSort.h"

//���Թ鲢����ݹ�汾
void Test1()
{
	int arr[] = { 1, 4, 2, 3, 5, 7, 6, 8, 9 };
	int size = sizeof(arr) / sizeof(arr[0]);

	ShowArray(arr, size);
	MergeSort(arr, size);
	ShowArray(arr, size);
}

//���Թ鲢����ǵݹ�汾
void Test2()
{
	int arr[] = { 1, 4, 2, 3, 5, 7, 6, 8, 9 };
	int size = sizeof(arr) / sizeof(arr[0]);

	MergeSortNonR(arr, size);
	ShowArray(arr, size);
}

int main()
{
	Test1();
	Test2();
	system("pause");
	return 0;
}