#include <stdio.h>
#include <stdbool.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};


//题目：翻转一棵二叉树
//
//示例：
//
//输入：[4, 2, 7, 1, 3, 6, 9]
//输出：[4, 7, 2, 9, 6, 3, 1]

struct TreeNode* invertTree(struct TreeNode* root){
	if (NULL == root)
	{
		return NULL;
	}
	//交换左右子树
	struct TreeNode* tmp = root->left;
	root->left = root->right;
	root->right = tmp;
	//进行递归
	invertTree(root->left);
	invertTree(root->right);

	return root;
}



//题目：相同的树
//给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。
//如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
//
//示例1：
//输入：p = [1, 2, 3], q = [1, 2, 3]
//输出：true
//
//示例2：
//输入：p = [1, 2, 1], q = [1, 1, 2]
//输出：false

bool isSameTree(struct TreeNode* p, struct TreeNode* q){
	if (NULL == p && NULL == q)
		return true;
	//结构判断
	if (NULL == p && NULL != q)
		return false;
	if (NULL == q && NULL != p)
		return false;
	//数值判断
	if (p->val != q->val)
		return false;
	//结构与数值都满足则进行递归
	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}