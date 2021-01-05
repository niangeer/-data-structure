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
	if (NULL == *pphead)                //������               
	{
		return;
	}
	else if (NULL == (*pphead)->next)  //һ��
	{
		free(*pphead);
		*pphead = NULL;
	}
	else                               //һ������
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

// ������ͷ��
void SlistPushFront(SlistNode** pphead, SlistDataType x)
{
	SlistNode* newNode = BuySlistNode(x);
	newNode->next = *pphead;
	*pphead = newNode;
}

// ������ͷɾ
void SlistPopFront(SlistNode** pphead)
{
	if (NULL == *pphead)               //������
	{
		return;
	}
	else                              //һ��+һ������
	{
		SlistNode* next = (*pphead)->next;
		free(*pphead);
		*pphead = next;
	}
}

//���������
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
	printf("Ҫ���ҵ����ݲ�����!\n");
	return NULL;
}

// ��������posλ��֮�����x
void SlistInsertAfter(SlistNode** pos, SlistDataType x)
{
	SlistNode* newNode = BuySlistNode(x);   
	if (NULL == *pos)                      //������
	{
		*pos = newNode;
	}
	else                                   //һ��+һ������
	{
		newNode->next = (*pos)->next;
		(*pos)->next = newNode;
	}
}

// ������ɾ��posλ��֮���ֵ
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
