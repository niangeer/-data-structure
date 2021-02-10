#include <stdio.h>
#include <stdbool.h>

//题目：另一棵树的子树
//给定两个非空二叉树s和t，检验s中是否包含和t具有相同结构和节点值的子树。
//s的一个子树包括s的一个节点和这个节点的所有子孙。s也可以看做它自身的一棵子树。
//
//示例1：
//
//输入：
//s[3, 4, 5, 1, 2]
//t[4, 1, 2]
//输出：true
//
//示例2：
//
//输入：
//s[3, 4, 5, 1, 2, NULL, NULL, 0]
//t[4, 1, 2]
//输出：false

struct TreeNode {
    int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
	if (NULL == p && NULL == q)
		return true;
	//结构不同
	if (NULL == p && NULL != q)
		return false;
	if (NULL == q && NULL != p)
		return false;
	//值不同
	if (p->val != q->val)
		return false;

	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t){
	//空树无子树
	if (NULL == s)
		return false;
	//若t为空树一定是子树
	if (NULL == t)
		return true;
	//将t树与s树当前节点比较
	if (true == isSameTree(s, t))
		return true;
	//当前节点不符合进行递归
	return isSubtree(s->left, t) || isSubtree(s->right, t);
}