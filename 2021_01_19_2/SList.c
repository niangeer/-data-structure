#include "SList.h"

// 动态申请一个节点
SlistNode* BuySlistNode(SlistDataType x)
{
	SlistNode *newNode = (SlistNode*)malloc(sizeof(SlistNode));
	if (NULL == newNode)
	{
		exit(-1);
	}
	newNode->data = x;
	newNode->next=NULL;
	return newNode;
}

// 单链表尾插
void SListPushBack(SlistNode** pphead, SlistDataType x)
{
	assert(pphead);
	SlistNode *newNode = BuySlistNode(x);
	if (NULL == *pphead)
	{
		*pphead = newNode;
	}

	else
	{
		SlistNode *tail = *pphead;
		while (tail->next)
		{
			tail = tail->next;
		}
		tail->next = newNode;
	}
}

// 单链表打印
void SListPrint(SlistNode* phead)
{
	SlistNode* cur = phead;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

// 单链表的尾删
void SListPopBack(SlistNode** pphead)
{
	assert(pphead);
	if (NULL == *pphead)
	{
		return;
	}
	else if (NULL == (*pphead)->next)
	{
		free(*pphead);
		(*pphead) = NULL;
	}
	else
	{
		SlistNode* prev = NULL;
		SlistNode* tail = *pphead;
		while (tail->next)
		{
			prev = tail;
			tail = tail->next;
		}
		prev->next = NULL;
		free(tail);
	}
}

// 单链表的头插
void SListPushFront(SlistNode** pphead, SlistDataType x)
{
	SlistNode *newNode = BuySlistNode(x);
	newNode->next = *pphead;
	*pphead = newNode;
}

// 单链表头删
void SListPopFront(SlistNode** pphead)
{
	assert(pphead);
	if (NULL == *pphead)
		return;
	else
	{
		SlistNode* newHead = (*pphead)->next;
		free(*pphead);
		*pphead = newHead;
	}
}

// 单链表查找
SlistNode* SListFind(SlistNode* phead, SlistDataType x)
{
	SlistNode *cur = phead;
	while (cur)
	{
		if (x == cur->data)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

// 单链表在pos位置之后插入x
void SListInsertAfter(SlistNode* pos, SlistDataType x)
{
	assert(pos);
	SlistNode* newNode = BuySlistNode(x);
	newNode->next = pos->next;
	pos->next = newNode;
}

// 单链表删除pos位置之后的值
void SListEraseAfter(SlistNode* pos)
{
	assert(pos&&pos->next);
	SlistNode *next = pos->next;
	pos->next = next->next;
	free(next);
}
