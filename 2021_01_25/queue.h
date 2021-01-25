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

#endif