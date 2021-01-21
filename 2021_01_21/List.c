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

// ˫������ͷ��
void ListPushFront(ListNode* phead, LTDataType x)
{
	assert(phead);

	ListNode *first = phead->next;
	ListNode *newNode = BuyListNode(x);

	phead->next = newNode;
	phead->prev = phead;

	newNode->next = first;
	first->prev = newNode;
}

// ˫������ͷɾ
void ListPopFront(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	ListNode *first = phead->next;
	ListNode *second = first->next;

	phead->next = second;
	second->prev = phead;
	free(first);
}

// ˫���������
ListNode* ListFind(ListNode* phead, LTDataType x)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (x == cur->data)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode *posPrev = pos->prev;
	ListNode *newNode = BuyListNode(x);

	posPrev->next = newNode;
	newNode->prev = posPrev;
	newNode->next = pos;
	pos->prev = newNode;
}

// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* posPrev = pos->prev;
	ListNode* posNext = pos->next;

	free(pos);
	posPrev->next = posNext;
	posNext->prev = posPrev;
}

//ֻ����ͷ��㣬�����������н��
void ListCreate(ListNode** pphead)
{
	assert(pphead);

	ListNode* cur = *pphead;
	while (cur != *pphead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	(*pphead)->next = *pphead;
	(*pphead)->prev = *pphead;
}

// ˫����������
void ListDestory(ListNode** pphead)
{
	assert(pphead);
	ListCreate(pphead);
	free(*pphead);
	*pphead = NULL;
}