#include "heap.h"

int main()
{
	int a[] = { 2, 25, 1, 3, 53, 2, 5, 4, 6, 3, 7 };
	heap hp;

	//建堆
	HeapInit(&hp, a, sizeof(a) / sizeof(a[0]));
	for (int i = 0; i < hp._size; i++)
	{
		printf("%d ", hp._a[i]);
	}
	printf("\n");

	//堆的插入
	HeapPush(&hp,0);
	for (int i = 0; i < hp._size; i++)
	{
		printf("%d ", hp._a[i]);
	}
	printf("\n");

	//堆的删除
	HeapPop(&hp);
	for (int i = 0; i < hp._size; i++)
	{
		printf("%d ", hp._a[i]);
	}
	printf("\n");

	//获取堆顶的数据
	printf("%d\n", HeapTop(&hp));

	//堆的销毁
	HeapDestory(&hp);
	system("pause");
	return 0;
}