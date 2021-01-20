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

// ˫������β��
void ListPushBack(ListNode* phead, LTDataType x);

//˫������ĳ�ʼ��
void ListInit(ListNode** pphead);

// ˫�������ӡ
void ListPrint(ListNode* phead);

// ˫������βɾ
void ListPopBack(ListNode* phead);

#endif