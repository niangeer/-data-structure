#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//请你仅使用两个栈实现先入先出队列。队列应当支持一般队列的支持的所有操作（push、pop、peek、empty）：
//
//实现 MyQueue 类：
//    1，void push(int x) 将元素 x 推到队列的末尾
//    2，int pop() 从队列的开头移除并返回元素
//    3，int peek() 返回队列开头的元素
//    4，boolean empty() 如果队列为空，返回 true ；否则，返回 false
//说明：
//      1，你只能使用标准的栈操作——也就是只有 push to top, peek / pop from top, size, 和 is empty 操作是合法的。 
//      2，你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
//
//示例：
//输入：
//["MyQueue", "push", "push", "peek", "pop", "empty"]
//[[], [1], [2], [], [], []]
//输出：
//[null, null, null, 1, 1, false]
//
//解释：
//MyQueue myQueue = new MyQueue();
//myQueue.push(1); // queue is: [1]
//myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
//myQueue.peek(); // return 1
//myQueue.pop(); // return 1, queue is [2]
//myQueue.empty(); // return false

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

