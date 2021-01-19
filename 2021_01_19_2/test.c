#include "SList.h"

int main()
{
	SlistNode* head = NULL;

	SListPushBack(&head, 1);
	SListPushBack(&head, 2);
	SListPushBack(&head, 3);
	SListPushBack(&head, 4);
	SListPushBack(&head, 5);
	SListPrint(head);

	SListPopBack(&head);
	SListPopBack(&head);
	SListPopBack(&head);
	SListPopBack(&head);
	SListPopBack(&head);
	SListPopBack(&head);
	SListPrint(head);

	SListPushFront(&head, 6);
	SListPushFront(&head, 7);
	SListPushFront(&head, 8);
	SListPushFront(&head, 9);
	SListPrint(head);

	//SListPopFront(&head);
	//SListPopFront(&head);
	//SListPopFront(&head);
	//SListPopFront(&head);
	//SListPopFront(&head);
	//SListPrint(head);

	SlistNode* Find = SListFind(head, 8);
	SListPrint(Find);
	SListInsertAfter(Find, 9);
	SListPrint(Find);

	SListEraseAfter(Find);
	SListEraseAfter(Find);
	SListEraseAfter(Find);
	SListPrint(Find);

	system("pause");
	return 0;
}
