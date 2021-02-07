#include <stdio.h>
#include <stdbool.h>

//题目：单值二叉树
//如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。
//只有给定的树是单值二叉树时，才返回 true；否则返回 false。
//
//示例1：
//输入：[1, 1, 1, 1, 1, null, 1]
//输出：true
//
//示例2：
//输入：[2, 2, 2, 5, 2]
//输出：false


 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };

bool isUnivalTree(struct TreeNode* root){

	//空树返回true
	if (NULL == root)
	{
		return true;
	}
	//当前节点与左孩子相比较
	if (root->left && root->val != root->left->val)
	{
		return false;
	}
	//当前节点与右孩子相比较
	if (root->right && root->val != root->right->val)
	{
		return false;
	}

	return isUnivalTree(root->left) && isUnivalTree(root->right);
}