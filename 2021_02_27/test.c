#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable: 4996)

//题目：
//
//编一个程序，读入用户输入的一串先序遍历字符串，根据此字符串建立一个二叉树
//（以指针方式存储）。 例如如下的先序遍历字符串：
//ABC##DE#G##F### 其中“#”表示的是空格，空格字符代表空树。
//建立起此二叉树以后，再对二叉树进行中序遍历，输出遍历结果
//
//输入描述：
//输入包括1行字符串，长度不超过100。
//
//输出描述：
//可能有多组测试数据，对于每组数据，
//输出将输入字符串建立二叉树后中序遍历的序列，每个字符后面都有一个空格。
//每个输出结果占一行。
//
//示例：
//
//输入：abc##de#g##f###
//输出：c b e g d f a

typedef struct TreeNode
{
	char _val;
	struct TreeNode* _left;
	struct TreeNode* _right;
}TreeNode;

//创建二叉树
TreeNode* CreateTree(char* str, int* pi)
{
	//遇到空树时
	if ('#' == str[*pi])
	{
		(*pi)++;
		return NULL;
	}
	//非空，创建节点
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->_val = str[*pi];
	(*pi)++;
	//将创建好的节点赋予关系
	node->_left = CreateTree(str, pi);
	node->_right = CreateTree(str, pi);

	return node;
}
//中序遍历
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
	//创建数组进行输入
	char str[100];
	scanf("%s", str);
	//创建二叉树
	int i = 0;
	TreeNode* root = CreateTree(str, &i);
	//进行中序遍历
	InOrder(root);

	return 0;
}