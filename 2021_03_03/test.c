#include "Sort.h"

//≤‚ ‘—°‘Ò≈≈–Ú
void Test1()
{
	int arr[] = { 3, 6, 5, 2, 1, 4, 9, 8, 7 };
	int size = sizeof(arr) / sizeof(arr[0]);

	ShowArray(arr, size);
	SelectSort(arr, size);
	ShowArray(arr, size);
}

//≤‚ ‘∂—≈≈–Ú
void Test2()
{
	int arr[] = { 3, 6, 5, 2, 1, 4, 9, 8, 7 };
	int size = sizeof(arr) / sizeof(arr[0]);

	ShowArray(arr, size);
	HeapSort(arr, size);
	ShowArray(arr, size);
}

int main()
{
	Test1();
	Test2();
	TestOP();
	system("pause");
	return 0;
}
