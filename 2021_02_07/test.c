#include <stdio.h>
#include <stdbool.h>

//��Ŀ����ֵ������
//���������ÿ���ڵ㶼������ͬ��ֵ����ô�ö��������ǵ�ֵ��������
//ֻ�и��������ǵ�ֵ������ʱ���ŷ��� true�����򷵻� false��
//
//ʾ��1��
//���룺[1, 1, 1, 1, 1, null, 1]
//�����true
//
//ʾ��2��
//���룺[2, 2, 2, 5, 2]
//�����false


 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };

bool isUnivalTree(struct TreeNode* root){

	//��������true
	if (NULL == root)
	{
		return true;
	}
	//��ǰ�ڵ���������Ƚ�
	if (root->left && root->val != root->left->val)
	{
		return false;
	}
	//��ǰ�ڵ����Һ�����Ƚ�
	if (root->right && root->val != root->right->val)
	{
		return false;
	}

	return isUnivalTree(root->left) && isUnivalTree(root->right);
}