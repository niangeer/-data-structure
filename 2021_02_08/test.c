#include <stdio.h>

//��Ŀ����������������
//����һ�����������ҳ��������ȡ�
//�����������Ϊ���ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�����
//˵�� : Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣
//
//ʾ����
//
//����������[3, 9, 20, null, null, 15, 7]
//�������������� 3

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int maxDepth(struct TreeNode* root){
	if (NULL == root)
		return 0;

	int leftDepth = maxDepth(root->left);
	int rightDepth = maxDepth(root->right);

	return leftDepth>rightDepth ? leftDepth + 1 : rightDepth + 1;
}
