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
// ��̬����һ���ڵ�
SlistNode* BuySlistNode(SlistDataType x);
// �������ӡ
void SListPrint(SlistNode* phead);
// ������β��
void SListPushBack(SlistNode** pphead, SlistDataType x);
// �������ͷ��
void SListPushFront(SlistNode** pphead, SlistDataType x);
// �������βɾ
void SListPopBack(SlistNode** pphead);
// ������ͷɾ
void SListPopFront(SlistNode** pphead);
// ���������
SlistNode* SListFind(SlistNode* phead, SlistDataType x);
// ��������posλ��֮�����x
void SListInsertAfter(SlistNode* pos, SlistDataType x);
// ������ɾ��posλ��֮���ֵ
void SListEraseAfter(SlistNode* pos);

#endif