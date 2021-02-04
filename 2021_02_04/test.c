#include "Heap.h"

void Test()
{
	int a[] = { 234, 4, 2, 25, 65, 47, 8, 98, 35, 9 };
	Heap hp;

	//测试堆的初始化
	HeapInit(&hp, a, sizeof(a) / sizeof(a[0]));
	for (int i = 0; i < hp._size; i++)
	{
		printf("%d ", hp._a[i]);
	}
	printf("\n");

	//测试堆的插入与获得堆顶数据
	HeapPush(&hp, 1);
	for (int i = 0; i < hp._size; i++)
	{
		printf("%d ", hp._a[i]);
	}
	printf("\n");
	printf("%d\n", HeapTop(&hp));

	//测试堆的删除
	HeapPop(&hp);
	for (int i = 0; i < hp._size; i++)
	{
		printf("%d ", hp._a[i]);
	}
	printf("\n");
	printf("%d\n", HeapTop(&hp));

	//测试堆的排序
	HeapSort(&hp);
	for (int i = 0; i < hp._size; i++)
	{
		printf("%d ", hp._a[i]);
	}
	printf("\n");

	//测试堆的销毁
	HeapDestory(&hp);
}

int main()
{
	Test();
	system("pause");
	return 0;
}