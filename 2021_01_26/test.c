#include <stdio.h>
#include <Windows.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>


//��Ŀ��
//����һ��ֻ����'(',')','{','}','[',']'���ַ��� s ���ж��ַ����Ƿ���Ч��
//��Ч�ַ��������㣺
//1�������ű�������ͬ���͵������űպϡ�
//2�������ű�������ȷ��˳��պϡ�

//ʾ��1��
//���룺s = "([)]"
//�����false
//
//ʾ��2��
//���룺s = "{[]}"
//�����true


typedef char STDataType;
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
void StackPush(Stack* pst, STDataType data);

//��ջ
void StackPop(Stack* pst);

//ջ������
STDataType StackTop(Stack* pst);

//ջ����Ч����
int StackSize(Stack* pst);

//ջ�Ƿ�Ϊ�գ��շ���1�����շ���0
int StackEmpty(Stack* pst);

//ջ��ʼ��
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

//ջ����
void StackDestory(Stack* pst)
{
	assert(pst);
	free(pst->_a);
	pst->_a = NULL;
	pst->_top = pst->_capacity = 0;
}

//��ջ
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

//��ջ
void StackPop(Stack* pst)
{
	assert(pst);
	assert(pst->_top);
	pst->_top -= 1;
}

//ջ������
STDataType StackTop(Stack* pst)
{
	assert(pst);
	assert(pst->_top);
	return pst->_a[pst->_top - 1];
}

//ջ����Ч����
int StackSize(Stack* pst)
{
	assert(pst);
	return pst->_top;
}

//ջ�Ƿ�Ϊ�գ��շ���1�����շ���0
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
		//����������ջ
		if (*s == '[' || *s == '{' || *s == '(')
		{
			StackPush(&st, *s);
			s++;
		}
		//�������ų�ջ��S�е�������Ч�ֽ���ƥ��
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