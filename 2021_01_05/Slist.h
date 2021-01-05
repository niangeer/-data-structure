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

// ������β��
void SlistPushBack(SlistNode** pphead, SlistDataType x);

// �������ӡ
void SlistShow(SlistNode* phead);

// ������βɾ
void SlistPopBack(SlistNode** pphead);

// ������ͷ��
void SlistPushFront(SlistNode** pphead, SlistDataType x);

// ������ͷɾ
void SlistPopFront(SlistNode** pphead);

//���������
SlistNode* SlistFind(SlistNode* phead,SlistDataType x);

// ��������posλ��֮�����x
void SlistInsertAfter(SlistNode** pos, SlistDataType x);

// ������ɾ��posλ��֮���ֵ
void SlistEraseAfter(SlistNode* pos);

#endif