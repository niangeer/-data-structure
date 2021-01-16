#include <stdio.h>

//����һ������ÿ���ڵ����һ���������ӵ����ָ�룬��ָ�����ָ�������е��κνڵ��սڵ㡣
//Ҫ�󷵻��������������
//������һ���� n ���ڵ���ɵ���������ʾ���� / ����е�����
//ÿ���ڵ���һ��[val, random_index] ��ʾ��
//     val��һ����ʾNode.val ��������
//     random_index�����ָ��ָ��Ľڵ���������Χ�� 0 �� n - 1���������ָ���κνڵ㣬��Ϊ null��
//
//ʾ��1 ��
//���룺head = [[7, null], [13, 0], [11, 4], [10, 2], [1, 0]]
//�����[[7, null], [13, 0], [11, 4], [10, 2], [1, 0]]

struct Node {
	int val;
	struct Node *next;
	struct Node *random;
};

typedef struct Node Node;
struct Node* copyRandomList(struct Node* head) {
	if (head == NULL)
	{
		return NULL;
	}

	Node *cur = head;
	while (cur)
	{
		Node *copy = (Node*)malloc(sizeof(Node));
		copy->next = NULL;
		copy->val = cur->val;

		Node* next = cur->next;
		cur->next = copy;
		copy->next = next;

		cur = next;
	}
	//�������ڵ��random
	cur = head;
	while (cur)
	{
		Node* copy = cur->next;
		if (cur->random)
		{
			copy->random = cur->random->next;
		}
		else
		{
			copy->random = NULL;
		}
		cur = cur->next->next;
	}
	//��
	cur = head;
	Node* copyHead = head->next;
	while (cur)
	{
		Node* copy = cur->next;
		Node* next = copy->next;

		cur->next = next;
		if (next)
		{
			copy->next = next->next;
		}
		else
		{
			copy->next = NULL;
		}
		cur = next;
	}
	return copyHead;
}
