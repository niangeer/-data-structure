#include "Heap.h"

void Test()
{
	int a[] = { 234, 4, 2, 25, 65, 47, 8, 98, 35, 9 };
	Heap hp;

	//���Զѵĳ�ʼ��
	HeapInit(&hp, a, sizeof(a) / sizeof(a[0]));
	for (int i = 0; i < hp._size; i++)
	{
		printf("%d ", hp._a[i]);
	}
	printf("\n");

	//���ԶѵĲ������öѶ�����
	HeapPush(&hp, 1);
	for (int i = 0; i < hp._size; i++)
	{
		printf("%d ", hp._a[i]);
	}
	printf("\n");
	printf("%d\n", HeapTop(&hp));

	//���Զѵ�ɾ��
	HeapPop(&hp);
	for (int i = 0; i < hp._size; i++)
	{
		printf("%d ", hp._a[i]);
	}
	printf("\n");
	printf("%d\n", HeapTop(&hp));

	//���Զѵ�����
	HeapSort(&hp);
	for (int i = 0; i < hp._size; i++)
	{
		printf("%d ", hp._a[i]);
	}
	printf("\n");

	//���Զѵ�����
	HeapDestory(&hp);
}

int main()
{
	Test();
	system("pause");
	return 0;
}