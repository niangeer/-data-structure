#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>
#include <Windows.h>
#include <assert.h>
#include <stdlib.h>

typedef int STDataType;

typedef struct Stack
{
	STDataType* _a;     //栈
	int _top;           //栈顶下标
	int _capacity;      //栈容量
}Stack;


// 初始化栈
void StackInit(Stack* pst);

// 入栈
void StackPush(Stack* pst, STDataType data);

// 出栈
void StackPop(Stack* pst);

// 获取栈顶元素
STDataType StackTop(Stack* pst);

// 获取栈中有效元素个数
int StackSize(Stack* pst);

// 检测栈是否为空，如果为空返回1，如果不为空返回0
int StackEmpty(Stack* pst);

// 销毁栈
void StackDestroy(Stack* pst);

#endif