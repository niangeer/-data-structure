#include <stdio.h>
#include <Windows.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>


//题目：
//给定一个只包括'(',')','{','}','[',']'的字符串 s ，判断字符串是否有效。
//有效字符串需满足：
//1，左括号必须用相同类型的右括号闭合。
//2，左括号必须以正确的顺序闭合。

//示例1：
//输入：s = "([)]"
//输出：false
//
//示例2：
//输入：s = "{[]}"
//输出：true


typedef char STDataType;
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
void StackPush(Stack* pst, STDataType data);

//出栈
void StackPop(Stack* pst);

//栈顶数据
STDataType StackTop(Stack* pst);

//栈的有效个数
int StackSize(Stack* pst);

//栈是否为空，空返回1，不空返回0
int StackEmpty(Stack* pst);

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

bool isValid(char * s){
	Stack st;
	StackInit(&st);
	bool ret;
	while (*s != '\0')
	{
		//将左括号入栈
		if (*s == '[' || *s == '{' || *s == '(')
		{
			StackPush(&st, *s);
			s++;
		}
		//将左括号出栈与S中的其它有效字节相匹配
		else
		{
			if (StackEmpty(&st))
			{
				ret = false;
				break;
			}
			char top = StackTop(&st);
			if (*s == '}'&&top != '{')
			{
				ret = false;
				break;
			}
			if (*s == ']'&&top != '[')
			{
				ret = false;
				break;
			}
			if (*s == ')'&&top != '(')
			{
				ret = false;
				break;
			}
			StackPop(&st);
			s++;
		}
	}
	if (*s == '\0')
	{
		ret = StackEmpty(&st);
	}
	StackDestory(&st);
	return ret;
}

int main()
{
	char* s = "()\0";
	isValid(s);
	system("pause");
	return 0;
}