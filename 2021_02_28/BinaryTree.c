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

//����������
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

// ����������
void BinaryTreeDestory(BTNode** root)
{
	if (NULL == *root)
		return;

	BinaryTreeDestory(&(*root)->_left);
	BinaryTreeDestory(&(*root)->_right);

	free(*root);
	*root = NULL;
}

// �������ڵ����
int BinaryTreeSize(BTNode* root)
{
	if (NULL == root)
		return 0;

	return 1 + BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);
}

// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	if (NULL == root)
		return 0;

	if (root->_left == NULL && root->_right == NULL)
		return 1;

	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (NULL == root)
		return 0;

	if (1 == k)
		return 1;

	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}

// ����������ֵΪx�Ľڵ�
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

// ������ǰ�����
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

// �������������
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

// �������������
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

// �������
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

		//������������Ϊ�գ������������
		if (front->_left)
			QueuePush(&q, front->_left);
		if (front->_right)
			QueuePush(&q, front->_right);
	}
	printf("\n");
	QueueDestory(&q);
}

// �ж϶������Ƿ�����ȫ������,�Ƿ���1�����Ƿ���0
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
	//����һ��α������
	BTNode* A = BinaryTreeCreate('A');
	BTNode* B = BinaryTreeCreate('B');
	BTNode* C = BinaryTreeCreate('C');
	BTNode* D = BinaryTreeCreate('D');
	BTNode* E = BinaryTreeCreate('E');
	A->_left = B;
	A->_right = C;
	B->_left = D;
	B->_right = E;

	//��������ǰ�����
	BinaryTreePrevOrder(A);
	printf("\n");

	//���������������
	BinaryTreeInOrder(A);
	printf("\n");

	//�������ĺ������
	BinaryTreePostOrder(A);
	printf("\n");

	//�������ڵ����
	int size = BinaryTreeSize(A);
	printf("%d\n", size);

	//������Ҷ�ӽڵ����
	int leafSize = BinaryTreeLeafSize(A);
	printf("%d\n", leafSize);

	//�������ĵ�K��ڵ����
	int kSize = BinaryTreeLevelKSize(A, 3);
	printf("%d\n", kSize);

	//����������ֵΪx�Ľڵ�
	BTNode* node = BinaryTreeFind(A, 'F');
	if (node)
		printf("%c\n", node->_data);
	else
		printf("NULL\n");

	//�������Ĳ������
	BinaryTreeLevelOrder(A);

	// �ж϶������Ƿ�����ȫ������,�Ƿ���1�����Ƿ���0
	int ret = BinaryTreeComplete(A);
	printf("%d\n", ret);

	//������������
	BinaryTreeDestory(&A);

	system("pause");
	return 0;
}