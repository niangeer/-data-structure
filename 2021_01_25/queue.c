#include "queue.h"

//队列初始化
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->_phead = pq->_tail = NULL;
}

//队列销毁
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

//队尾入队列
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

//队头出队列
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

//获取队头数据
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->_phead);

	return pq->_phead->_data;
}

//获取队尾数据
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->_phead);

	return pq->_tail->_data;
}

// 检测队列是否为空，为空返回1，不为空返回0
int QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->_phead == NULL ? 1 : 0;
}

// 获取队列中有效元素个数
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
