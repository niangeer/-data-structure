#include "Stack.h"

// ��ʼ��ջ
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

// ��ջ
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

// ��ջ
void StackPop(Stack* pst)
{
	assert(pst);
	assert(pst->_top);
	pst->_top--;
}

// ��ȡջ��Ԫ��
STDataType StackTop(Stack* pst)
{
	assert(pst);
	assert(pst->_top);
	return pst->_a[pst->_top - 1];
}

// ��ȡջ����ЧԪ�ظ���
int StackSize(Stack* pst)
{
	assert(pst);
	return pst->_top;
}

// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0
int StackEmpty(Stack* pst)
{
	assert(pst);
	return pst->_top == 0 ? 1 : 0;
}

// ����ջ
void StackDestroy(Stack* pst)
{
	assert(pst);
	free(pst->_a);
	pst->_capacity = pst->_top = 0;
}