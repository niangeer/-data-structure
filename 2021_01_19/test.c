#include "SeqList.h"

int main()
{
	SeqList s ;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
    SeqListShow(&s);

	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListShow(&s);

	SeqListPushFront(&s, 9);
	SeqListPushFront(&s, 8);
	SeqListPushFront(&s, 7);
	SeqListPushFront(&s, 6);
	SeqListShow(&s);

	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListShow(&s);

	SeqListPushFront(&s, 6);
	SeqListPushFront(&s, 6);
	SeqListShow(&s);
  
	int pos = SeqListFind(&s, 4);
	printf("%d\n", pos);

	SeqListInsert(&s, 0, 9);
	SeqListShow(&s);

	SeqListErase(&s, 0);
	SeqListShow(&s);

	SeqListDestory(&s);

	system("pause");
	return 0;
}