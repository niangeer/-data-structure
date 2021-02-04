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

//堆的初始化
void HeapInit(Heap* php, HPDataType* a, int n);

//堆的销毁
void HeapDestory(Heap* php);

//堆的插入
void HeapPush(Heap* php, HPDataType x);

//堆的删除
void HeapPop(Heap* php);

//获取堆顶的数据
HPDataType HeapTop(Heap* php);

//堆的排序
void HeapSort(Heap* php);

#endif