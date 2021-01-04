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

// ������β��
void SlistPushBack(SlistNode** pphead, SlistDataType x);

// �������ӡ
void SlistShow(SlistNode* phead);

// ������βɾ
void SlistPopBack(SlistNode** pphead);

#endif