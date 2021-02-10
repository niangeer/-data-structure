#include <stdio.h>
#include <stdbool.h>

//��Ŀ����һ����������
//���������ǿն�����s��t������s���Ƿ������t������ͬ�ṹ�ͽڵ�ֵ��������
//s��һ����������s��һ���ڵ������ڵ���������sҲ���Կ����������һ��������
//
//ʾ��1��
//
//���룺
//s[3, 4, 5, 1, 2]
//t[4, 1, 2]
//�����true
//
//ʾ��2��
//
//���룺
//s[3, 4, 5, 1, 2, NULL, NULL, 0]
//t[4, 1, 2]
//�����false

struct TreeNode {
    int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
	if (NULL == p && NULL == q)
		return true;
	//�ṹ��ͬ
	if (NULL == p && NULL != q)
		return false;
	if (NULL == q && NULL != p)
		return false;
	//ֵ��ͬ
	if (p->val != q->val)
		return false;

	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t){
	//����������
	if (NULL == s)
		return false;
	//��tΪ����һ��������
	if (NULL == t)
		return true;
	//��t����s����ǰ�ڵ�Ƚ�
	if (true == isSameTree(s, t))
		return true;
	//��ǰ�ڵ㲻���Ͻ��еݹ�
	return isSubtree(s->left, t) || isSubtree(s->right, t);
}