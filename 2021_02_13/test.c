#include <stdio.h>

//题目：二叉树的中序遍历
//
//给定一个二叉树的根节点 root ，返回它的 中序 遍历。
//
//示例1：
//输入：root = [1, null, 2, 3]
//输出：[1, 3, 2]
//
//示例2：
//输入：root = []
//输出：[]

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

/**
* Note: The returned array must be malloced, assume caller calls free().
*/

//二叉树的节点个数
int TreeSize(struct TreeNode* root)
{
	if (NULL == root)
		return 0;

	return 1 + TreeSize(root->left) + TreeSize(root->right);
}
//二叉树的中序遍历
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
	//size充当retArr的下标
	int size = 0;
	InOrder(root, retArr, &size);

	*returnSize = treeSize;
	return retArr;
}