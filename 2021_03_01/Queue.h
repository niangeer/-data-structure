#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <assert.h>

extern struct BinaryTreeNode;

typedef struct BinaryTreeNode* QDataType;

//��ʽ�ṹ����ʾ����
typedef struct QueueNode
{
	QDataType _data;
	struct QueueNode* _next;
}QueueNode;

//���еĽṹ
typedef struct Queue
{
	QueueNode* _phead;
	QueueNode* _tail;
}Queue;

//��ʼ������
void QueueInit(Queue* pq);

//���ٶ���
void QueueDestory(Queue* pq);

//��β�����
void QueuePush(Queue* pq, QDataType data);

//��ͷ������
void QueuePop(Queue* pq);

//��ȡ��ͷ����
QDataType QueueFront(Queue* pq);

//��ȡ��β����
QDataType QueueBack(Queue* pq);

//��ȡ������Ч����
int QueueSize(Queue* pq);

//�����Ƿ�Ϊ�գ�Ϊ�շ���1����Ϊ�շ���0
int QueueEmpty(Queue* pq);

#endif 