#include "Slist.h"

// ��̬����һ���ڵ�
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

// ������β��
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

// �������ӡ
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

// ������βɾ
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