#ifndef _SLIST_H_
#define _SLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <assert.h>

typedef int SlistDataType;

typedef struct SlistNode 
{
	SlistDataType data;
	struct SlistNode* next;
}SlistNode;


void SlistNodeInit(SlistNode** pphead);
// 动态申请一个节点
SlistNode* BuySlistNode(SlistDataType x);
// 单链表打印
void SListPrint(SlistNode* phead);
// 单链表尾插
void SListPushBack(SlistNode** pphead, SlistDataType x);
// 单链表的头插
void SListPushFront(SlistNode** pphead, SlistDataType x);
// 单链表的尾删
void SListPopBack(SlistNode** pphead);
// 单链表头删
void SListPopFront(SlistNode** pphead);
// 单链表查找
SlistNode* SListFind(SlistNode* phead, SlistDataType x);
// 单链表在pos位置之后插入x
void SListInsertAfter(SlistNode* pos, SlistDataType x);
// 单链表删除pos位置之后的值
void SListEraseAfter(SlistNode* pos);

#endif