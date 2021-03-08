#include "Stack.h"

//栈初始化
void StackInit(Stack* pst)
{
	assert(pst);
	pst->_a = (STDataType*)malloc(sizeof(STDataType)* 4);
	if (NULL == pst->_a)
	{
		exit(-1);
	}
	pst->_capacity = 4;
	pst->_top = 0;
}

//栈销毁
void StackDestory(Stack* pst)
{
	assert(pst);
	free(pst->_a);
	pst->_a = NULL;
	pst->_top = pst->_capacity = 0;
}

//入栈
void StackPush(Stack* pst, STDataType data)
{
	assert(pst);
	if (pst->_capacity == pst->_top)
	{
		STDataType* p = (STDataType*)realloc(pst->_a, sizeof(STDataType)* 2 * pst->_capacity);
		if (NULL == p)
		{
			exit(-1);
		}
		pst->_a = p;
		pst->_capacity *= 2;
	}
	pst->_a[pst->_top] = data;
	pst->_top += 1;
}

//出栈
void StackPop(Stack* pst)
{
	assert(pst);
	assert(pst->_top);
	pst->_top -= 1;
}

//栈顶数据
STDataType StackTop(Stack* pst)
{
	assert(pst);
	assert(pst->_top);
	return pst->_a[pst->_top - 1];
}

//栈的有效个数
int StackSize(Stack* pst)
{
	assert(pst);
	return pst->_top;
}

//栈是否为空，空返回1，不空返回0
int StackEmpty(Stack* pst)
{
	assert(pst);
	return pst->_top == 0 ? 1 : 0;
}