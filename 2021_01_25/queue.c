#include "queue.h"

//���г�ʼ��
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->_phead = pq->_tail = NULL;
}

//��������
void QueueDestory(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->_phead;
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
	newNode->_next = NULL;
	newNode->_data = data;

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

	QueueNode* Next = pq->_phead->_next;
	free(pq->_phead);
	pq->_phead = Next;

	if (NULL == pq->_phead)
		pq->_tail = NULL;
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
	assert(pq->_phead);

	return pq->_tail->_data;
}

// �������Ƿ�Ϊ�գ�Ϊ�շ���1����Ϊ�շ���0
int QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->_phead == NULL ? 1 : 0;
}

// ��ȡ��������ЧԪ�ظ���
int QueueSize(Queue* pq)
{
	assert(pq);

	QueueNode* cur = pq->_phead;
	int size = 0;
	while (cur)
	{
		cur = cur->_next;
		size++;
	}
	return size;
}
