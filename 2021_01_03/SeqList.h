#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include <stdio.h>
#include <Windows.h>
#include <assert.h>
#include <stdlib.h>

#pragma warning(disable:4996)

#define CAP 2
#define INC_CAP 2

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* a;      // 指向动态开辟的数组
	int size;           // 有效数据个数
	int capacity;       // 容量空间的大小
}SL,SeqList;


// 顺序表初始化
void SeqListInit(SeqList* ps);

//顺序表展示
void SeqListShow(SeqList* ps);

//释放内存
void SeqListDestory(SeqList* ps);

//顺序表尾插
void SeqListPushBack(SeqList* ps, SLDataType x);

//顺序表尾删
void SeqListPopBack(SeqList* ps);

//顺序表头插
void SeqListPushFront(SeqList* ps, SLDataType x);

//顺序表头删
void SeqListPopFront(SeqList* ps);

// 顺序表在pos位置插入x
void SeqListInsert(SeqList* ps, int pos, SLDataType x);

// 顺序表删除pos位置的值
void SeqListErase(SeqList* ps, int pos);

// 顺序表查找
int SeqListFind(SeqList* ps, SLDataType x);

#endif