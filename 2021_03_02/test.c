#include "Sort.h"

//≤‚ ‘÷±Ω”≤Â»Î≈≈–Ú
void Test1()
{
	int arr[] = { 0, 4, 3, 1, 5, 6, 7, 3, 7, 8, 9, 7, 9 };
	int size = sizeof(arr) / sizeof(arr[0]);
	PrintArr(arr, size);
	InsertSort(arr, size);
	PrintArr(arr, size);
}

//≤‚ ‘œ£∂˚≈≈–Ú
void Test2()
{
	int arr[] = { 0, 4, 3, 1, 5, 6, 7, 3, 7, 8, 9, 7, 9 };
	int size = sizeof(arr) / sizeof(arr[0]);
	PrintArr(arr, size);
	ShellSort(arr, size);
	PrintArr(arr, size);
}

int main()
{
	Test1();
	Test2();

	TestOP();
	system("pause");
	return 0;
}