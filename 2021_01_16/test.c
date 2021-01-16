#include <stdio.h>

//给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
//要求返回这个链表的深拷贝。
//我们用一个由 n 个节点组成的链表来表示输入 / 输出中的链表。
//每个节点用一个[val, random_index] 表示：
//     val：一个表示Node.val 的整数。
//     random_index：随机指针指向的节点索引（范围从 0 到 n - 1）；如果不指向任何节点，则为 null。
//
//示例1 ：
//输入：head = [[7, null], [13, 0], [11, 4], [10, 2], [1, 0]]
//输出：[[7, null], [13, 0], [11, 4], [10, 2], [1, 0]]

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
	//处理拷贝节点的random
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
	//拆
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
