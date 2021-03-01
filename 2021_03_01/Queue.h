#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <assert.h>

extern struct BinaryTreeNode;

typedef struct BinaryTreeNode* QDataType;

//链式结构：表示队列
typedef struct QueueNode
{
	QDataType _data;
	struct QueueNode* _next;
}QueueNode;

//队列的结构
typedef struct Queue
{
	QueueNode* _phead;
	QueueNode* _tail;
}Queue;

//初始化队列
void QueueInit(Queue* pq);

//销毁队列
void QueueDestory(Queue* pq);

//队尾入队列
void QueuePush(Queue* pq, QDataType data);

//队头出队列
void QueuePop(Queue* pq);

//获取队头数据
QDataType QueueFront(Queue* pq);

//获取队尾数据
QDataType QueueBack(Queue* pq);

//获取队列有效个数
int QueueSize(Queue* pq);

//队列是否为空，为空返回1，不为空返回0
int QueueEmpty(Queue* pq);

#endif 