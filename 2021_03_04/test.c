#include "Sort.h"

//≤‚ ‘√∞≈›≈≈–Ú
void Test1()
{
	int arr[] = { 7, 3, 4, 1, 2, 6, 5, 8, 9 };
	int size = sizeof(arr) / sizeof(arr[0]);

	ShowArray(arr, size);
	BubbleSort(arr, size);
	ShowArray(arr, size);
}

//≤‚ ‘øÏ≈≈
void Test2()
{
	int arr[] = { 7, 3, 4, 1, 2, 6, 5, 8, 9 };
	int size = sizeof(arr) / sizeof(arr[0]);

	QuickSort(arr, 0, size - 1);
	ShowArray(arr, size);
}

int main()
{
	Test1();
	Test2();
	system("pause");
	return 0;
}