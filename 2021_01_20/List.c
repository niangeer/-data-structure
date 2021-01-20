#include "List.h"

ListNode* BuyListNode(LTDataType x)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (NULL == newNode)
	{
		exit(-1);
	}
	newNode->next = NULL;
	newNode->prev = NULL;
	newNode->data = x;

	return newNode;
}

//双向链表的初始化
void ListInit(ListNode** pphead)
{
	*pphead = BuyListNode(0);
	(*pphead)->next = *pphead;
	(*pphead)->prev = *pphead;
}

// 双向链表尾插
void ListPushBack(ListNode* phead, LTDataType x)
{
	assert(phead);

	ListNode* tail = phead->prev;
	ListNode* newNode = BuyListNode(x);

	tail->next = newNode;
	newNode->prev = tail;
	newNode->next = phead;
	phead->prev = newNode;
}

// 双向链表打印
void ListPrint(ListNode* phead)
{
	assert(phead);
	ListNode *cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

// 双向链表尾删
void ListPopBack(ListNode* phead)
{
	assert(phead&&phead != phead->next);
	ListNode *tail = phead->prev;
	ListNode *tailPrev = tail->prev;

	tailPrev->next = phead;
	phead->prev = tailPrev;
	free(tail);
	tail = NULL;
}