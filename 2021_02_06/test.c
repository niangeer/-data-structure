#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>

typedef char BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

//ǰ�����
void PrevOrder(BTNode* root)
{
	if (NULL == root)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->_data);
	PrevOrder(root->_left);
	PrevOrder(root->_right);
}

//�������
void InOrder(BTNode* root)
{
	if (NULL == root)
	{
		printf("NULL ");
		return;
	}

	InOrder(root->_left);
	printf("%c ", root->_data);
	InOrder(root->_right);
}

//�������
void PostOrder(BTNode* root)
{
	if (NULL == root)
	{
		printf("NULL ");
		return;
	}
	PostOrder(root->_left);
	PostOrder(root->_right);
	printf("%c ", root->_data);
}

//����һ���������ڵ�
BTNode* CreateNode(int x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (NULL == node)
	{
		exit(-1);
	}
	node->_data = x;
	node->_left = NULL;
	node->_right = NULL;

	return node;
}

int main()
{
	//����һ��α��
	BTNode* A = CreateNode('A');
	BTNode* B = CreateNode('B');
	BTNode* C = CreateNode('C');
	BTNode* D = CreateNode('D');
	BTNode* E = CreateNode('E');
	A->_left = B;
	A->_right = C;
	B->_left = D;
	B->_right = E;

	//ǰ�����
	PrevOrder(A);
	printf("\n");

	//�������
	InOrder(A);
	printf("\n");

	//�������
	PostOrder(A);
	printf("\n");

	system("pause");
	return 0;
}