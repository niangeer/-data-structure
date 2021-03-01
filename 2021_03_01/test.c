#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "Queue.h"

typedef char BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

//二叉树的层序遍历
void BinaryTreeLevelOrder(BTNode* root)
{
	if (NULL == root)
	{
		return;
	}

	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		printf("%c ", front->_data);

		//左右子树非空则使其进入队列
		if (front->_left)
			QueuePush(&q, front->_left);
		if (front->_right)
			QueuePush(&q, front->_right);
	}
	printf("\n");
	QueueDestory(&q);
}

//是否为完全二叉树，是返回1，不是返回0
int BinaryTreeComplete(BTNode* root)
{
	if (NULL == root)
	{
		return 1;
	}

	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		if (NULL == front)
		{
			break;
		}

		QueuePush(&q, front->_left);
		QueuePush(&q, front->_right);
	}

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front)
		{
			QueueDestory(&q);
			return 0;
		}
	}
	QueueDestory(&q);
	return 1;
}

//二叉树的构建
BTNode* BinaryTreeCreate(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (NULL == node)
		exit(-1);

	node->_data = x;
	node->_left = NULL;
	node->_right = NULL;

	return node;
}

int main()
{
	BTNode* A = BinaryTreeCreate('A');
	BTNode* B = BinaryTreeCreate('B');
	BTNode* C = BinaryTreeCreate('C');
	BTNode* D = BinaryTreeCreate('D');
	BTNode* E = BinaryTreeCreate('E');
	A->_left = B;
	A->_right = C;
	B->_left = D;
	B->_right = E;
	//二叉树的层序遍历
	BinaryTreeLevelOrder(A);
	//是否为完全二叉树
	int ret = BinaryTreeComplete(A);
	printf("%d\n", ret);

	system("pause");
	return 0;
}