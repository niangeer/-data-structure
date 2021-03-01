#include "Queue.h"

//��ʼ������
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->_phead = pq->_tail = NULL;
}

//���ٶ���
void QueueDestory(Queue* pq)
{
	assert(pq);
	QueueNode *cur = pq->_phead;
	while (cur)
	{
		QueueNode* Next = cur->_next;
		free(cur);
		cur = Next;
	}
	pq->_phead = pq->_tail = NULL;
}

//��β�����
void QueuePush(Queue* pq, QDataType data)
{
	assert(pq);
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (NULL == newNode)
	{
		exit(-1);
	}
	newNode->_data = data;
	newNode->_next = NULL;
	if (NULL == pq->_phead)
	{
		pq->_phead = pq->_tail = newNode;
	}
	else
	{
		pq->_tail->_next = newNode;
		pq->_tail = newNode;
	}
}

//��ͷ������
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->_phead);

	QueueNode* newHead = pq->_phead->_next;
	free(pq->_phead);
	pq->_phead = newHead;

	if (NULL == pq->_phead)
	{
		pq->_tail = NULL;
	}
}

//��ȡ��ͷ����
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->_phead);
	return pq->_phead->_data;
}

//��ȡ��β����
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->_tail);
	return pq->_tail->_data;
}

//��ȡ������Ч����
int QueueSize(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->_phead;
	int size = 0;
	while (cur)
	{
		size++;
		cur = cur->_next;
	}

	return size;
}

//�����Ƿ�Ϊ�գ�Ϊ�շ���1����Ϊ�շ���0
int QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->_phead == NULL ? 1 : 0;
}