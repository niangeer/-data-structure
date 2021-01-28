#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

//ʹ�ö���ʵ��ջ�����в�����
//
//push(x) --Ԫ�� x ��ջ
//pop() --�Ƴ�ջ��Ԫ��
//top() --��ȡջ��Ԫ��
//empty() --����ջ�Ƿ�Ϊ��
//ע�⣺
//
//1����ֻ��ʹ�ö��еĻ�����������Ҳ����push to back,peek / pop from front,size,�� is empty ��Щ�����ǺϷ��ġ�
//2������ʹ�õ�����Ҳ��֧�ֶ��С� �����ʹ�� list ���� deque��˫�˶��У���ģ��һ������ , ֻҪ�Ǳ�׼�Ķ��в������ɡ�
//3������Լ������в���������Ч�ģ�����, ��һ���յ�ջ������� pop ���� top ��������

typedef int QDataType;

typedef struct QueueNode
{
	QDataType _data;
	struct QueueNode* _next;
}QueueNode;

typedef struct Queue
{
	QueueNode* _phead;
	QueueNode* _tail;
}Queue;

//���г�ʼ��
void QueueInit(Queue* pq);

//��������
void QueueDestory(Queue* pq);

//��β�����
void QueuePush(Queue* pq, QDataType data);

//��ͷ������
void QueuePop(Queue* pq);

//��ȡ��ͷ����
QDataType QueueFront(Queue* pq);

//��ȡ��β����
QDataType QueueBack(Queue* pq);

// �������Ƿ�Ϊ�գ�Ϊ�շ���1����Ϊ�շ���0
int QueueEmpty(Queue* pq);

// ��ȡ��������ЧԪ�ظ���
int QueueSize(Queue* pq);

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

typedef struct {
	Queue _q1;
	Queue _q2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
	MyStack* st = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&st->_q1);
	QueueInit(&st->_q2);

	return st;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	if (!QueueEmpty(&obj->_q1))
	{
		QueuePush(&obj->_q1, x);
	}
	else
	{
		QueuePush(&obj->_q2, x);
	}
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
	Queue* empty = &obj->_q1;
	Queue* nonEmpty = &obj->_q2;
	if (QueueEmpty(&obj->_q2))
	{
		empty = &obj->_q2;
		nonEmpty = &obj->_q1;
	}
	while (QueueSize(nonEmpty)>1)
	{
		QueuePush(empty, QueueFront(nonEmpty));
		QueuePop(nonEmpty);
	}
	int top = QueueFront(nonEmpty);
	QueuePop(nonEmpty);
	return top;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
	if (!QueueEmpty(&obj->_q1))
	{
		return QueueBack(&obj->_q1);
	}
	else
	{
		return QueueBack(&obj->_q2);
	}
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
	return QueueEmpty(&obj->_q1) && QueueEmpty(&obj->_q2);
}

void myStackFree(MyStack* obj) {
	QueueDestory(&obj->_q1);
	QueueDestory(&obj->_q2);

	free(obj);
}
