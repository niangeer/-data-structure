#include <stdio.h>
#include <stdbool.h>

//题目：对称二叉树
//给定一个二叉树，检查它是否是镜像对称的。
//
//示例1：
//输入：[1, 2, 2, 3, 4, 4, 3]
//输出：true
//
//示例2：
//输入：[1, 2, 2, null, 3, null, 3]
//输出：false

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

//判断是否相同
bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
	if (NULL == p && NULL == q)
		return true;
	//判断结构是否相同
	if (NULL == p || NULL == q)
		return false;
	//判断值是否相同
	if (p->val != q->val)
		return false;

	return isSameTree(p->left, q->right) && isSameTree(p->right, q->left);
}

bool isSymmetric(struct TreeNode* root){
	//空树为对称树
	if (NULL == root)
		return true;

	struct TreeNode* left = root->left;
	struct TreeNode* right = root->right;

	return isSameTree(left, right);
}

