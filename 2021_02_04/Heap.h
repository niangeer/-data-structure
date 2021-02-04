#ifndef _HEAP_H_
#define _HEAP_H_

#include <stdio.h>
#include <Windows.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;

//�ѵĳ�ʼ��
void HeapInit(Heap* php, HPDataType* a, int n);

//�ѵ�����
void HeapDestory(Heap* php);

//�ѵĲ���
void HeapPush(Heap* php, HPDataType x);

//�ѵ�ɾ��
void HeapPop(Heap* php);

//��ȡ�Ѷ�������
HPDataType HeapTop(Heap* php);

//�ѵ�����
void HeapSort(Heap* php);

#endif