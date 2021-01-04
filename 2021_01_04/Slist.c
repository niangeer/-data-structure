#include "Slist.h"

// 动态申请一个节点
static SlistNode* BuySlistNode(SlistDataType x)
{
	SlistNode* newNode = (SlistNode*)malloc(sizeof(SlistNode));
	if (NULL == newNode)
	{
		printf("malloc error!\n");
		exit(1);
	}
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

// 单链表尾插
void SlistPushBack(SlistNode** pphead, SlistDataType x)
{
	SlistNode* newNode = BuySlistNode(x);
	if (NULL == *pphead)
	{
		*pphead = newNode;
	}
	else
	{
		SlistNode* tail = *pphead;
		while (NULL != tail->next)
		{
			tail = tail->next;
		}
		tail->next = newNode;
	}
}

// 单链表打印
void SlistShow(SlistNode* phead)
{
	SlistNode* cur = phead;
	while (NULL != cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

// 单链表尾删
void SlistPopBack(SlistNode** pphead)
{
	if (NULL == *pphead)
	{
		return;
	}
	else if (NULL == (*pphead)->next)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SlistNode* tail = *pphead;
		SlistNode* prev = NULL;
		while (NULL != tail->next)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		prev->next = NULL;
	}
}