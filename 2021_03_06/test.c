#include "Stack.h"

void ShowArray(int* a, int n)
{
	assert(a);

	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//²âÊÔ¿ìËÙÅÅÐò·ÇµÝ¹é°æ±¾
void Test()
{
	int arr[] = { 2, 3, 5, 1, 4, 6, 9, 8, 7 };
	int size = sizeof(arr) / sizeof(arr[0]);

	ShowArray(arr, size);
	QuickSortNonR(arr, 0, size - 1);
	ShowArray(arr, size);
}

int main()
{
	Test();
	system("pause");
	return 0;
}