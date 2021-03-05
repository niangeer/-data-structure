#include "QuickSort.h"

void Test()
{
	int arr[] = { 3, 2, 4, 1, 6, 9, 8, 5, 7 };
	int size = sizeof(arr) / sizeof(arr[0]);

	ShowArray(arr, size);
	QuickSort(arr, 0, size - 1);
	ShowArray(arr, size);
}

int main()
{
	Test();
	system("pause");
	return 0;
}