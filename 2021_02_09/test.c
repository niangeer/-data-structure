#include <stdio.h>
#include <stdbool.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};


//��Ŀ����תһ�ö�����
//
//ʾ����
//
//���룺[4, 2, 7, 1, 3, 6, 9]
//�����[4, 7, 2, 9, 6, 3, 1]

struct TreeNode* invertTree(struct TreeNode* root){
	if (NULL == root)
	{
		return NULL;
	}
	//������������
	struct TreeNode* tmp = root->left;
	root->left = root->right;
	root->right = tmp;
	//���еݹ�
	invertTree(root->left);
	invertTree(root->right);

	return root;
}



//��Ŀ����ͬ����
//�������ö������ĸ��ڵ� p �� q ����дһ���������������������Ƿ���ͬ��
//����������ڽṹ����ͬ�����ҽڵ������ͬ��ֵ������Ϊ��������ͬ�ġ�
//
//ʾ��1��
//���룺p = [1, 2, 3], q = [1, 2, 3]
//�����true
//
//ʾ��2��
//���룺p = [1, 2, 1], q = [1, 1, 2]
//�����false

bool isSameTree(struct TreeNode* p, struct TreeNode* q){
	if (NULL == p && NULL == q)
		return true;
	//�ṹ�ж�
	if (NULL == p && NULL != q)
		return false;
	if (NULL == q && NULL != p)
		return false;
	//��ֵ�ж�
	if (p->val != q->val)
		return false;
	//�ṹ����ֵ����������еݹ�
	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}