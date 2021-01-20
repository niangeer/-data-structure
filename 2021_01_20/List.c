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

//˫������ĳ�ʼ��
void ListInit(ListNode** pphead)
{
	*pphead = BuyListNode(0);
	(*pphead)->next = *pphead;
	(*pphead)->prev = *pphead;
}

// ˫������β��
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

// ˫�������ӡ
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

// ˫������βɾ
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