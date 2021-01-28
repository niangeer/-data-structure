#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

//使用队列实现栈的下列操作：
//
//push(x) --元素 x 入栈
//pop() --移除栈顶元素
//top() --获取栈顶元素
//empty() --返回栈是否为空
//注意：
//
//1，你只能使用队列的基本操作——也就是push to back,peek / pop from front,size,和 is empty 这些操作是合法的。
//2，你所使用的语言也许不支持队列。 你可以使用 list 或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
//3，你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用 pop 或者 top 操作）。

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

//队列初始化
void QueueInit(Queue* pq);

//队列销毁
void QueueDestory(Queue* pq);

//队尾入队列
void QueuePush(Queue* pq, QDataType data);

//队头出队列
void QueuePop(Queue* pq);

//获取队头数据
QDataType QueueFront(Queue* pq);

//获取队尾数据
QDataType QueueBack(Queue* pq);

// 检测队列是否为空，为空返回1，不为空返回0
int QueueEmpty(Queue* pq);

// 获取队列中有效元素个数
int QueueSize(Queue* pq);

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
