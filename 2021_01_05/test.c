#include "Slist.h"

//测试尾插
void TestSlist1()   
{
	SlistNode* head = NULL;

	SlistPushBack(&head, 1);
	SlistPushBack(&head, 2);
	SlistPushBack(&head, 3);
	SlistPushBack(&head, 4);
	SlistShow(head);
}

//测试尾删
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

//测试头插
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

//测试头删
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

//测试查找和修改
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

//测试单链表在pos位置之后插入x
void TestSlist6()
{
	////空链表
	//SlistNode* pos = NULL;
	//SlistInsertAfter(&pos, 1);
	//SlistInsertAfter(&pos, 2);
	//SlistShow(pos);

	////一个结点
	//SlistNode* head = NULL;
	//SlistPushBack(&head, 1);
	//SlistNode* pos = head;
	//SlistInsertAfter(&pos, 5);
	//SlistInsertAfter(&pos, 6);
	//SlistShow(pos);

	//一个以上结点
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

// 单链表删除pos位置之后的值
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