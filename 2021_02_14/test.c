#include <stdio.h>

//��Ŀ���������
//����һ�����������������ĺ��������
//
//ʾ����
//���� : [1, null, 2, 3]
//��� : [3, 2, 1]

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

/**
* Note: The returned array must be malloced, assume caller calls free().
*/

int TreeSize(struct TreeNode* root)
{
	if (NULL == root)
		return 0;

	return 1 + TreeSize(root->left) + TreeSize(root->right);
}

void PosOrder(struct TreeNode* root, int* retArr, int* psize)
{
	if (NULL == root)
		return;

	PosOrder(root->left, retArr, psize);
	PosOrder(root->right, retArr, psize);
	retArr[*psize] = root->val;
	(*psize)++;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize){
	int treeSize = TreeSize(root);
	int* retArr = (int*)malloc(sizeof(int)*treeSize);

	int size = 0;
	PosOrder(root, retArr, &size);

	*returnSize = treeSize;
	return retArr;
}