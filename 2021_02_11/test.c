#include <stdio.h>
#include <stdbool.h>

//��Ŀ���Գƶ�����
//����һ����������������Ƿ��Ǿ���ԳƵġ�
//
//ʾ��1��
//���룺[1, 2, 2, 3, 4, 4, 3]
//�����true
//
//ʾ��2��
//���룺[1, 2, 2, null, 3, null, 3]
//�����false

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

//�ж��Ƿ���ͬ
bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
	if (NULL == p && NULL == q)
		return true;
	//�жϽṹ�Ƿ���ͬ
	if (NULL == p || NULL == q)
		return false;
	//�ж�ֵ�Ƿ���ͬ
	if (p->val != q->val)
		return false;

	return isSameTree(p->left, q->right) && isSameTree(p->right, q->left);
}

bool isSymmetric(struct TreeNode* root){
	//����Ϊ�Գ���
	if (NULL == root)
		return true;

	struct TreeNode* left = root->left;
	struct TreeNode* right = root->right;

	return isSameTree(left, right);
}

