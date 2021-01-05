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
	if (NULL == *pphead)                //空链表               
	{
		return;
	}
	else if (NULL == (*pphead)->next)  //一个
	{
		free(*pphead);
		*pphead = NULL;
	}
	else                               //一个以上
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

// 单链表头插
void SlistPushFront(SlistNode** pphead, SlistDataType x)
{
	SlistNode* newNode = BuySlistNode(x);
	newNode->next = *pphead;
	*pphead = newNode;
}

// 单链表头删
void SlistPopFront(SlistNode** pphead)
{
	if (NULL == *pphead)               //空链表
	{
		return;
	}
	else                              //一个+一个以上
	{
		SlistNode* next = (*pphead)->next;
		free(*pphead);
		*pphead = next;
	}
}

//单链表查找
SlistNode* SlistFind(SlistNode* phead, SlistDataType x)
{
	SlistNode* cur = phead;
	while (NULL != cur)
	{
		if (x == cur->data)
		{
			return cur;
		}
		cur = cur->next;
	}
	printf("要查找的数据不存在!\n");
	return NULL;
}

// 单链表在pos位置之后插入x
void SlistInsertAfter(SlistNode** pos, SlistDataType x)
{
	SlistNode* newNode = BuySlistNode(x);   
	if (NULL == *pos)                      //空链表
	{
		*pos = newNode;
	}
	else                                   //一个+一个以上
	{
		newNode->next = (*pos)->next;
		(*pos)->next = newNode;
	}
}

// 单链表删除pos位置之后的值
void SlistEraseAfter(SlistNode* pos)
{
	assert(pos);
	if (NULL != pos->next)
	{
		SlistNode* next = pos->next;
		SlistNode* nextnext = next->next;
		pos->next = nextnext;
		free(next);
	}
}
