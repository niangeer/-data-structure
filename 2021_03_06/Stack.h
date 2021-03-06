#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <assert.h>

//快速排序非递归版本
void QuickSortNonR(int *a, int left, int right);

typedef int STDataType;

typedef struct Stack
{
	STDataType* _a;  //栈
	int _top;        //入栈个数
	int _capacity;   //栈容量
}Stack;

//栈初始化
void StackInit(Stack* pst);

//栈销毁
void StackDestory(Stack* pst);

//入栈
void StackPush(Stack* pst,STDataType data);

//出栈
void StackPop(Stack* pst);

//栈顶数据
STDataType StackTop(Stack* pst);

//栈的有效个数
int StackSize(Stack* pst);

//栈是否为空，空返回1，不空返回0
int StackEmpty(Stack* pst);

#endif