#ifndef _HEAP_H_
#define _HEAP_H_

#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <assert.h>

typedef int HPDataType;

typedef struct heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}heap;

//�ѳ�ʼ��
void HeapInit(heap* php, HPDataType* a, int n);

//������
void HeapDestory(heap* php);

//�Ѳ���
void HeapPush(heap* php, HPDataType x);

//��ɾ��
void HeapPop(heap* php);

//��ȡ�Ѷ�����
HPDataType HeapTop(heap* php);

#endif