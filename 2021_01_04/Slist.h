#ifndef _SLIST_H_
#define _SLIST_H_

#include <stdio.h>
#include <Windows.h>

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

#endif