#include "List.h"

void TestList1()
{
	//����β��
	ListNode* phead = NULL;
	ListInit(&phead);
	ListPushBack(phead, 1);
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPushBack(phead, 4);
	ListPrint(phead);

	//����βɾ
	ListPopBack(phead);
	ListPopBack(phead);
	ListPopBack(phead);
	ListPopBack(phead);
	ListPopBack(phead);
	ListPrint(phead);
}

int main()
{
	TestList1();
	system("pause");
	return 0;
}