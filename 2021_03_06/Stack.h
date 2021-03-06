#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <assert.h>

//��������ǵݹ�汾
void QuickSortNonR(int *a, int left, int right);

typedef int STDataType;

typedef struct Stack
{
	STDataType* _a;  //ջ
	int _top;        //��ջ����
	int _capacity;   //ջ����
}Stack;

//ջ��ʼ��
void StackInit(Stack* pst);

//ջ����
void StackDestory(Stack* pst);

//��ջ
void StackPush(Stack* pst,STDataType data);

//��ջ
void StackPop(Stack* pst);

//ջ������
STDataType StackTop(Stack* pst);

//ջ����Ч����
int StackSize(Stack* pst);

//ջ�Ƿ�Ϊ�գ��շ���1�����շ���0
int StackEmpty(Stack* pst);

#endif