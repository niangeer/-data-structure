#include "SeqList.h"

TestSeqList()
{
	SeqList s;
	SeqListInit(&s);          //��ʼ��

	SeqListPushBack(&s, 1);   //����β��
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListShow(&s);

	SeqListPopBack(&s);    //����βɾ
	SeqListShow(&s);

	SeqListPushFront(&s, 5);   //����ͷ��
	SeqListShow(&s);
	 
	SeqListPopFront(&s);     //����ͷɾ
	SeqListShow(&s);

	SeqListInsert(&s, 0, 9);    //����pos���
	SeqListInsert(&s, 4, 8);
	SeqListShow(&s);

	SeqListErase(&s, 4);    //����pos��ɾ
	SeqListShow(&s);

	int pos = SeqListFind(&s, 3);     //���Բ���
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