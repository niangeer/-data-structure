#include "Sort.h"
#include "Stack.h"

//������ͨ��������
void Test1()
{
	int arr[] = { 2, 3, 1, 4, 6, 8, 9, 5, 7 };
	int size = sizeof(arr) / sizeof(arr[0]);

	ShowArray(arr, size);
	InsertSort(arr, size);
	ShowArray(arr, size);
}

//����ϣ������
void Test2()
{
	int arr[] = { 2, 3, 1, 4, 6, 8, 9, 5, 7 };
	int size = sizeof(arr) / sizeof(arr[0]);

	ShellSort(arr, size);
	ShowArray(arr, size);
}

//����ѡ������
void Test3()
{
	int arr[] = { 2, 3, 1, 4, 6, 8, 9, 5, 7 };
	int size = sizeof(arr) / sizeof(arr[0]);

	SelectSort(arr, size);
	ShowArray(arr, size);
}

//���Զ���
void Test4()
{
	int arr[] = { 2, 3, 1, 4, 6, 8, 9, 5, 7 };
	int size = sizeof(arr) / sizeof(arr[0]);

	HeapSort(arr, size);
	ShowArray(arr, size);
}

//����ð������
void Test5()
{
	int arr[] = { 2, 3, 1, 4, 6, 8, 9, 5, 7 };
	int size = sizeof(arr) / sizeof(arr[0]);

	BubbleSort(arr, size);
	ShowArray(arr, size);
}

//���Կ�������ݹ�汾
void Test6()
{
	int arr[] = { 2, 3, 1, 4, 6, 8, 9, 5, 7 };
	int size = sizeof(arr) / sizeof(arr[0]);

	QuickSort(arr, 0, size-1);
	ShowArray(arr, size);
}

//���Կ�������ǵݹ�汾
void Test7()
{
	int arr[] = { 2, 3, 1, 4, 6, 8, 9, 5, 7 };
	int size = sizeof(arr) / sizeof(arr[0]);

	QuickSortNonR(arr, 0, size - 1);
	ShowArray(arr, size);
}

//���Թ鲢����ݹ�汾
void Test8()
{
	int arr[] = { 2, 3, 1, 4, 6, 8, 9, 5, 7 };
	int size = sizeof(arr) / sizeof(arr[0]);

	MergeSort(arr, size);
	ShowArray(arr, size);
}

//���Թ鲢����ǵݹ�汾
void Test9()
{
	int arr[] = { 2, 3, 1, 4, 6, 8, 9, 5, 7 };
	int size = sizeof(arr) / sizeof(arr[0]);

	MergeSortNonR(arr, size);
	ShowArray(arr, size);
}

int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();
	Test8();
	Test9();

	system("pause");
	return 0;
}