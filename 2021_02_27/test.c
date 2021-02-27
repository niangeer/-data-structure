#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable: 4996)

//��Ŀ��
//
//��һ�����򣬶����û������һ����������ַ��������ݴ��ַ�������һ��������
//����ָ�뷽ʽ�洢���� �������µ���������ַ�����
//ABC##DE#G##F### ���С�#����ʾ���ǿո񣬿ո��ַ����������
//������˶������Ժ��ٶԶ����������������������������
//
//����������
//�������1���ַ��������Ȳ�����100��
//
//���������
//�����ж���������ݣ�����ÿ�����ݣ�
//����������ַ���������������������������У�ÿ���ַ����涼��һ���ո�
//ÿ��������ռһ�С�
//
//ʾ����
//
//���룺abc##de#g##f###
//�����c b e g d f a

typedef struct TreeNode
{
	char _val;
	struct TreeNode* _left;
	struct TreeNode* _right;
}TreeNode;

//����������
TreeNode* CreateTree(char* str, int* pi)
{
	//��������ʱ
	if ('#' == str[*pi])
	{
		(*pi)++;
		return NULL;
	}
	//�ǿգ������ڵ�
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->_val = str[*pi];
	(*pi)++;
	//�������õĽڵ㸳���ϵ
	node->_left = CreateTree(str, pi);
	node->_right = CreateTree(str, pi);

	return node;
}
//�������
void InOrder(TreeNode* root)
{
	if (NULL == root)
		return;

	InOrder(root->_left);
	printf("%c ", root->_val);
	InOrder(root->_right);
}
int main()
{
	//���������������
	char str[100];
	scanf("%s", str);
	//����������
	int i = 0;
	TreeNode* root = CreateTree(str, &i);
	//�����������
	InOrder(root);

	return 0;
}