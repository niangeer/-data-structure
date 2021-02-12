#include <stdio.h>
#include <stdbool.h>

//��Ŀ��ƽ�������
//����һ�����������ж����Ƿ��Ǹ߶�ƽ��Ķ�������
//
//�����У�һ�ø߶�ƽ�����������Ϊ��
//һ��������ÿ���ڵ� ���������������ĸ߶Ȳ�ľ���ֵ������ 1 ��
//
//ʾ��1��
//���룺root = [3, 9, 20, null, null, 15, 7]
//�����true
//
//ʾ��2��
//���룺root = [1, 2, 2, 3, 3, null, null, 4, 4]
//�����false

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

//������������
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
	//��������������Ȳ����1ʱ������ƽ�������
	int size = abs(TreeDepth(root->left) - TreeDepth(root->right));
	if (size>1)
		return false;
	else
		return isBalanced(root->left) && isBalanced(root->right);
}
