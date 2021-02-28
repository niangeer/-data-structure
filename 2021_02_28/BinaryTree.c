#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include "Queue.h"

typedef char BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

//创建二叉树
BTNode* BinaryTreeCreate(BTDataType a)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (NULL == node)
		exit(-1);

	node->_data = a;
	node->_left = NULL;
	node->_right = NULL;

	return node;	
}

// 二叉树销毁
void BinaryTreeDestory(BTNode** root)
{
	if (NULL == *root)
		return;

	BinaryTreeDestory(&(*root)->_left);
	BinaryTreeDestory(&(*root)->_right);

	free(*root);
	*root = NULL;
}

// 二叉树节点个数
int BinaryTreeSize(BTNode* root)
{
	if (NULL == root)
		return 0;

	return 1 + BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);
}

// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (NULL == root)
		return 0;

	if (root->_left == NULL && root->_right == NULL)
		return 1;

	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (NULL == root)
		return 0;

	if (1 == k)
		return 1;

	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}

// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (NULL == root)
	{
		return NULL;
	}

	if (x == root->_data)
	{
		return root;
	}

	BTNode* node = BinaryTreeFind(root->_left, x);
	if (node != NULL)
	{
		return node;
	}
	node = BinaryTreeFind(root->_right, x);
	if (node != NULL)
	{
		return node;
	}

	return NULL;
}

// 二叉树前序遍历
void BinaryTreePrevOrder(BTNode* root)
{
	if (NULL == root)
	{
		printf("NULL ");
		return;
	}

	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}

// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	if (NULL == root)
	{
		printf("NULL ");
		return;
	}

	BinaryTreeInOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreeInOrder(root->_right);
}

// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	if (NULL == root)
	{
		printf("NULL ");
		return;
	}

	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
	printf("%c ", root->_data);
}

// 层序遍历
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

		//若左右子树不为空，则让其进队列
		if (front->_left)
			QueuePush(&q, front->_left);
		if (front->_right)
			QueuePush(&q, front->_right);
	}
	printf("\n");
	QueueDestory(&q);
}

// 判断二叉树是否是完全二叉树,是返回1，不是返回0
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
			break;

		QueuePush(&q,front->_left);
		QueuePush(&q,front->_right);
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
int main()
{
	//构建一棵伪二叉树
	BTNode* A = BinaryTreeCreate('A');
	BTNode* B = BinaryTreeCreate('B');
	BTNode* C = BinaryTreeCreate('C');
	BTNode* D = BinaryTreeCreate('D');
	BTNode* E = BinaryTreeCreate('E');
	A->_left = B;
	A->_right = C;
	B->_left = D;
	B->_right = E;

	//二叉树的前序遍历
	BinaryTreePrevOrder(A);
	printf("\n");

	//二叉树的中序遍历
	BinaryTreeInOrder(A);
	printf("\n");

	//二叉树的后序遍历
	BinaryTreePostOrder(A);
	printf("\n");

	//二叉树节点个数
	int size = BinaryTreeSize(A);
	printf("%d\n", size);

	//二叉树叶子节点个数
	int leafSize = BinaryTreeLeafSize(A);
	printf("%d\n", leafSize);

	//二叉树的第K层节点个数
	int kSize = BinaryTreeLevelKSize(A, 3);
	printf("%d\n", kSize);

	//二叉树查找值为x的节点
	BTNode* node = BinaryTreeFind(A, 'F');
	if (node)
		printf("%c\n", node->_data);
	else
		printf("NULL\n");

	//二叉树的层序遍历
	BinaryTreeLevelOrder(A);

	// 判断二叉树是否是完全二叉树,是返回1，不是返回0
	int ret = BinaryTreeComplete(A);
	printf("%d\n", ret);

	//二叉树的销毁
	BinaryTreeDestory(&A);

	system("pause");
	return 0;
}