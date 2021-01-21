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

// 双向链表头插
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

// 双向链表头删
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

// 双向链表查找
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

// 双向链表在pos的前面进行插入
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

// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* posPrev = pos->prev;
	ListNode* posNext = pos->next;

	free(pos);
	posPrev->next = posNext;
	posNext->prev = posPrev;
}

//只保留头结点，清理其它所有结点
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

// 双向链表销毁
void ListDestory(ListNode** pphead)
{
	assert(pphead);
	ListCreate(pphead);
	free(*pphead);
	*pphead = NULL;
}