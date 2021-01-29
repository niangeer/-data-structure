#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//�����ʹ������ջʵ�������ȳ����С�����Ӧ��֧��һ����е�֧�ֵ����в�����push��pop��peek��empty����
//
//ʵ�� MyQueue �ࣺ
//    1��void push(int x) ��Ԫ�� x �Ƶ����е�ĩβ
//    2��int pop() �Ӷ��еĿ�ͷ�Ƴ�������Ԫ��
//    3��int peek() ���ض��п�ͷ��Ԫ��
//    4��boolean empty() �������Ϊ�գ����� true �����򣬷��� false
//˵����
//      1����ֻ��ʹ�ñ�׼��ջ��������Ҳ����ֻ�� push to top, peek / pop from top, size, �� is empty �����ǺϷ��ġ� 
//      2������ʹ�õ�����Ҳ��֧��ջ�������ʹ�� list ���� deque��˫�˶��У���ģ��һ��ջ��ֻҪ�Ǳ�׼��ջ�������ɡ�
//
//ʾ����
//���룺
//["MyQueue", "push", "push", "peek", "pop", "empty"]
//[[], [1], [2], [], [], []]
//�����
//[null, null, null, 1, 1, false]
//
//���ͣ�
//MyQueue myQueue = new MyQueue();
//myQueue.push(1); // queue is: [1]
//myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
//myQueue.peek(); // return 1
//myQueue.pop(); // return 1, queue is [2]
//myQueue.empty(); // return false

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

typedef struct {
	Stack _pushST;
	Stack _popST;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
	MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&q->_pushST);
	StackInit(&q->_popST);

	return q;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
	StackPush(&obj->_pushST, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
	int front = myQueuePeek(obj);
	StackPop(&obj->_popST);
	return front;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
	if (!StackEmpty(&obj->_popST))
	{
		return StackTop(&obj->_popST);
	}
	else
	{
		while (!StackEmpty(&obj->_pushST))
		{
			StackPush(&obj->_popST, StackTop(&obj->_pushST));
			StackPop(&obj->_pushST);
		}

		return StackTop(&obj->_popST);
	}
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
	return StackEmpty(&obj->_pushST) && StackEmpty(&obj->_popST);
}

void myQueueFree(MyQueue* obj) {
	StackDestory(&obj->_pushST);
	StackDestory(&obj->_popST);

	free(obj);
}

/**
* Your MyQueue struct will be instantiated and called as such:
* MyQueue* obj = myQueueCreate();
* myQueuePush(obj, x);

* int param_2 = myQueuePop(obj);

* int param_3 = myQueuePeek(obj);

* bool param_4 = myQueueEmpty(obj);

* myQueueFree(obj);
*/

