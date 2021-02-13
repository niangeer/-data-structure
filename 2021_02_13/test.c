#include <stdio.h>

//��Ŀ�����������������
//
//����һ���������ĸ��ڵ� root ���������� ���� ������
//
//ʾ��1��
//���룺root = [1, null, 2, 3]
//�����[1, 3, 2]
//
//ʾ��2��
//���룺root = []
//�����[]

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

/**
* Note: The returned array must be malloced, assume caller calls free().
*/

//�������Ľڵ����
int TreeSize(struct TreeNode* root)
{
	if (NULL == root)
		return 0;

	return 1 + TreeSize(root->left) + TreeSize(root->right);
}
//���������������
void InOrder(struct TreeNode* root, int* retArr, int* psize)
{
	if (NULL == root)
		return;

	InOrder(root->left, retArr, psize);
	retArr[*psize] = root->val;
	(*psize)++;
	InOrder(root->right, retArr, psize);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
	int treeSize = TreeSize(root);
	int* retArr = (int *)malloc(sizeof(int)*treeSize);
	if (NULL == retArr)
	{
		exit(-1);
	}
	//size�䵱retArr���±�
	int size = 0;
	InOrder(root, retArr, &size);

	*returnSize = treeSize;
	return retArr;
}