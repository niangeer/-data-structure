#ifndef _LISTNODE_H_
#define _LISTNODE_H_

#include <stdio.h>
#include <Windows.h>
#include <assert.h>

typedef int LTDataType;

typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}ListNode;

// 双向链表尾插
void ListPushBack(ListNode* phead, LTDataType x);

//双向链表的初始化
void ListInit(ListNode** pphead);

// 双向链表打印
void ListPrint(ListNode* phead);

// 双向链表尾删
void ListPopBack(ListNode* phead);

#endif