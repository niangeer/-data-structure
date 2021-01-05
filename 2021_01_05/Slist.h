#ifndef _SLIST_H_
#define _SLIST_H_

#include <stdio.h>
#include <Windows.h>
#include <assert.h>

typedef int SlistDataType;

typedef struct SlistNode
{
	SlistDataType data;
	struct SlistNode* next;
}SlistNode;

// 单链表尾插
void SlistPushBack(SlistNode** pphead, SlistDataType x);

// 单链表打印
void SlistShow(SlistNode* phead);

// 单链表尾删
void SlistPopBack(SlistNode** pphead);

// 单链表头插
void SlistPushFront(SlistNode** pphead, SlistDataType x);

// 单链表头删
void SlistPopFront(SlistNode** pphead);

//单链表查找
SlistNode* SlistFind(SlistNode* phead,SlistDataType x);

// 单链表在pos位置之后插入x
void SlistInsertAfter(SlistNode** pos, SlistDataType x);

// 单链表删除pos位置之后的值
void SlistEraseAfter(SlistNode* pos);

#endif