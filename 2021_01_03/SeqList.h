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
	SLDataType* a;      // ָ��̬���ٵ�����
	int size;           // ��Ч���ݸ���
	int capacity;       // �����ռ�Ĵ�С
}SL,SeqList;


// ˳����ʼ��
void SeqListInit(SeqList* ps);

//˳���չʾ
void SeqListShow(SeqList* ps);

//�ͷ��ڴ�
void SeqListDestory(SeqList* ps);

//˳���β��
void SeqListPushBack(SeqList* ps, SLDataType x);

//˳���βɾ
void SeqListPopBack(SeqList* ps);

//˳���ͷ��
void SeqListPushFront(SeqList* ps, SLDataType x);

//˳���ͷɾ
void SeqListPopFront(SeqList* ps);

// ˳�����posλ�ò���x
void SeqListInsert(SeqList* ps, int pos, SLDataType x);

// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* ps, int pos);

// ˳������
int SeqListFind(SeqList* ps, SLDataType x);

#endif