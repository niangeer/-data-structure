#include "Slist.h"

int main()
{
	SlistNode* head = NULL;
	SlistPushBack(&head, 1);     
	SlistPushBack(&head, 2);
	SlistPushBack(&head, 3);
	SlistPushBack(&head, 4);
	SlistShow(head);

	SlistPopBack(&head);
	SlistPopBack(&head);
	SlistPopBack(&head);
	SlistPopBack(&head);
	SlistPopBack(&head);
	SlistShow(head);

	system("pause");
	return 0;
}