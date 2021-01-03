#include "SeqList.h"

TestSeqList()
{
	SeqList s;
	SeqListInit(&s);          //≥ı ºªØ

	SeqListPushBack(&s, 1);   //≤‚ ‘Œ≤≤Â
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListShow(&s);

	SeqListPopBack(&s);    //≤‚ ‘Œ≤…æ
	SeqListShow(&s);

	SeqListPushFront(&s, 5);   //≤‚ ‘Õ∑≤Â
	SeqListShow(&s);
	 
	SeqListPopFront(&s);     //≤‚ ‘Õ∑…æ
	SeqListShow(&s);

	SeqListInsert(&s, 0, 9);    //≤‚ ‘posµ„≤Â
	SeqListInsert(&s, 4, 8);
	SeqListShow(&s);

	SeqListErase(&s, 4);    //≤‚ ‘posµ„…æ
	SeqListShow(&s);

	int pos = SeqListFind(&s, 3);     //≤‚ ‘≤È’“
	printf("%d\n", pos);
	if (-1 != pos)
	{
		SeqListErase(&s, pos);
	}
	SeqListShow(&s);

	SeqListDestory(&s);
}

int main()
{
	TestSeqList();
	system("pause");
	return 0;
}