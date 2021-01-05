#include "Slist.h"

//����β��
void TestSlist1()   
{
	SlistNode* head = NULL;

	SlistPushBack(&head, 1);
	SlistPushBack(&head, 2);
	SlistPushBack(&head, 3);
	SlistPushBack(&head, 4);
	SlistShow(head);
}

//����βɾ
void TestSlist2()
{
	SlistNode* head = NULL;

	SlistPopBack(&head);
	SlistPopBack(&head);
	SlistPopBack(&head);
	SlistPopBack(&head);
	SlistPopBack(&head);
	SlistShow(head);
}

//����ͷ��
void TestSlist3()
{
	SlistNode* head = NULL;

	SlistPushFront(&head, 8);
	SlistPushFront(&head, 7);
	SlistPushFront(&head, 6);
	SlistPushFront(&head, 5);
	SlistPushBack(&head, 4);
	SlistPushFront(&head, 9);
	SlistShow(head);
}

//����ͷɾ
void TestSlist4()
{
	SlistNode* head = NULL;

	SlistPopFront(&head);
	SlistPopFront(&head);
	SlistPopFront(&head);
	SlistPopFront(&head);
	SlistPopFront(&head);
	SlistPopFront(&head);
	SlistPopFront(&head);
	SlistShow(head);
}

//���Բ��Һ��޸�
void TestSlist5()
{
	SlistNode* head = NULL;

	SlistPushFront(&head, 8);
	SlistPushFront(&head, 7);
	SlistPushFront(&head, 6);
	SlistPushFront(&head, 5);
	SlistPushBack(&head, 4);
	SlistPushFront(&head, 9);
	SlistShow(head);
	SlistNode* fine = SlistFind(head, 6);
	if (NULL != fine)
	{
		fine->data = 9999;
	}
	SlistShow(head);
}

//���Ե�������posλ��֮�����x
void TestSlist6()
{
	////������
	//SlistNode* pos = NULL;
	//SlistInsertAfter(&pos, 1);
	//SlistInsertAfter(&pos, 2);
	//SlistShow(pos);

	////һ�����
	//SlistNode* head = NULL;
	//SlistPushBack(&head, 1);
	//SlistNode* pos = head;
	//SlistInsertAfter(&pos, 5);
	//SlistInsertAfter(&pos, 6);
	//SlistShow(pos);

	//һ�����Ͻ��
	SlistNode* head = NULL;
	SlistPushBack(&head, 1);
	SlistPushBack(&head, 2);
	SlistPushBack(&head, 3);
	SlistPushBack(&head, 4);
	SlistNode* pos = head;
	SlistInsertAfter(&pos, 5);
	SlistInsertAfter(&pos, 6);
	SlistShow(pos);
}

// ������ɾ��posλ��֮���ֵ
TestSlist7()
{
	SlistNode* head = NULL;
	SlistPushBack(&head, 1);
	SlistPushBack(&head, 2);
	SlistPushBack(&head, 3);

	SlistNode* pos = head;
	SlistInsertAfter(&pos, 4);
	SlistInsertAfter(&pos, 5);
	SlistShow(pos);

	SlistEraseAfter(pos);
	SlistEraseAfter(pos);
	SlistEraseAfter(pos);
	SlistEraseAfter(pos);
	SlistEraseAfter(pos);
	SlistEraseAfter(pos);
	SlistShow(pos);
}
int main()
{
	//TestSlist1();
	//TestSlist2();
	//TestSlist3();
	//TestSlist4();
	//TestSlist5();
	//TestSlist6();
	TestSlist7();
	system("pause");
	return 0;
}