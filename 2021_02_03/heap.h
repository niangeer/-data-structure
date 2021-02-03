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

//堆初始化
void HeapInit(heap* php, HPDataType* a, int n);

//堆销毁
void HeapDestory(heap* php);

//堆插入
void HeapPush(heap* php, HPDataType x);

//堆删除
void HeapPop(heap* php);

//获取堆顶数据
HPDataType HeapTop(heap* php);

#endif