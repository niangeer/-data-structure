#include "SList.h"

// ��̬����һ���ڵ�
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

// ������β��
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

// �������ӡ
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

// �������βɾ
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

// �������ͷ��
void SListPushFront(SlistNode** pphead, SlistDataType x)
{
	SlistNode *newNode = BuySlistNode(x);
	newNode->next = *pphead;
	*pphead = newNode;
}

// ������ͷɾ
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

// ���������
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

// ��������posλ��֮�����x
void SListInsertAfter(SlistNode* pos, SlistDataType x)
{
	assert(pos);
	SlistNode* newNode = BuySlistNode(x);
	newNode->next = pos->next;
	pos->next = newNode;
}

// ������ɾ��posλ��֮���ֵ
void SListEraseAfter(SlistNode* pos)
{
	assert(pos&&pos->next);
	SlistNode *next = pos->next;
	pos->next = next->next;
	free(next);
}
