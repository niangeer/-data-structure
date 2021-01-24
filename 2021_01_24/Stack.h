#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>
#include <Windows.h>
#include <assert.h>
#include <stdlib.h>

typedef int STDataType;

typedef struct Stack
{
	STDataType* _a;     //ջ
	int _top;           //ջ���±�
	int _capacity;      //ջ����
}Stack;


// ��ʼ��ջ
void StackInit(Stack* pst);

// ��ջ
void StackPush(Stack* pst, STDataType data);

// ��ջ
void StackPop(Stack* pst);

// ��ȡջ��Ԫ��
STDataType StackTop(Stack* pst);

// ��ȡջ����ЧԪ�ظ���
int StackSize(Stack* pst);

// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ���1�������Ϊ�շ���0
int StackEmpty(Stack* pst);

// ����ջ
void StackDestroy(Stack* pst);

#endif