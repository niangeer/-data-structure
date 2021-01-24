#include "Stack.h"

// 初始化栈
void StackInit(Stack* pst)
{
	assert(pst);
	pst->_a = (STDataType*)malloc(sizeof(STDataType)*4);
	if (NULL == pst->_a)
	{
		exit(-1);
	}
	pst->_top = 0;
	pst->_capacity = 4;
}

// 入栈
void StackPush(Stack* pst, STDataType data)
{
	assert(pst);
	if (pst->_top == pst->_capacity)
	{
		STDataType* p = (STDataType*)realloc(pst->_a,sizeof(STDataType)*(pst->_capacity) * 2);
		if (NULL == p)
		{
			exit(-1);
		}
		pst->_a = p;
		pst->_capacity *= 2;
	}
	pst->_a[pst->_top] = data;
	pst->_top++;
}

// 出栈
void StackPop(Stack* pst)
{
	assert(pst);
	assert(pst->_top);
	pst->_top--;
}

// 获取栈顶元素
STDataType StackTop(Stack* pst)
{
	assert(pst);
	assert(pst->_top);
	return pst->_a[pst->_top - 1];
}

// 获取栈中有效元素个数
int StackSize(Stack* pst)
{
	assert(pst);
	return pst->_top;
}

// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0
int StackEmpty(Stack* pst)
{
	assert(pst);
	return pst->_top == 0 ? 1 : 0;
}

// 销毁栈
void StackDestroy(Stack* pst)
{
	assert(pst);
	free(pst->_a);
	pst->_capacity = pst->_top = 0;
}