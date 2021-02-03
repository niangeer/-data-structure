#include "heap.h"

int main()
{
	int a[] = { 2, 25, 1, 3, 53, 2, 5, 4, 6, 3, 7 };
	heap hp;

	//����
	HeapInit(&hp, a, sizeof(a) / sizeof(a[0]));
	for (int i = 0; i < hp._size; i++)
	{
		printf("%d ", hp._a[i]);
	}
	printf("\n");

	//�ѵĲ���
	HeapPush(&hp,0);
	for (int i = 0; i < hp._size; i++)
	{
		printf("%d ", hp._a[i]);
	}
	printf("\n");

	//�ѵ�ɾ��
	HeapPop(&hp);
	for (int i = 0; i < hp._size; i++)
	{
		printf("%d ", hp._a[i]);
	}
	printf("\n");

	//��ȡ�Ѷ�������
	printf("%d\n", HeapTop(&hp));

	//�ѵ�����
	HeapDestory(&hp);
	system("pause");
	return 0;
}