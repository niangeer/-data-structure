#include <stdio.h>
#include <stdbool.h>

//题目：平衡二叉树
//给定一个二叉树，判断它是否是高度平衡的二叉树。
//
//本题中，一棵高度平衡二叉树定义为：
//一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
//
//示例1：
//输入：root = [3, 9, 20, null, null, 15, 7]
//输出：true
//
//示例2：
//输入：root = [1, 2, 2, 3, 3, null, null, 4, 4]
//输出：false

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

//计算二叉树深度
int TreeDepth(struct TreeNode* root)
{
	if (NULL == root)
		return 0;

	int leftDepth = TreeDepth(root->left);
	int rightDepth = TreeDepth(root->right);

	return leftDepth>rightDepth ? 1 + leftDepth : 1 + rightDepth;
}

bool isBalanced(struct TreeNode* root){
	if (NULL == root)
		return true;
	//当左右子树的深度差大于1时，不是平衡二叉树
	int size = abs(TreeDepth(root->left) - TreeDepth(root->right));
	if (size>1)
		return false;
	else
		return isBalanced(root->left) && isBalanced(root->right);
}
