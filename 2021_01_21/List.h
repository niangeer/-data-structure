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

// ˫������ͷ��
void ListPushFront(ListNode* phead, LTDataType x);

// ˫������ͷɾ
void ListPopFront(ListNode* phead);

// ˫���������
ListNode* ListFind(ListNode* phead, LTDataType x);

// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x);

// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos);

//ֻ����ͷ��㣬�����������н��
void ListCreate(ListNode** pphead);

// ˫����������
void ListDestory(ListNode** pphead);

#endif