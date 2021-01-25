#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdio.h>
#include <Windows.h>
#include <assert.h>
#include <stdlib.h>

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

#endif