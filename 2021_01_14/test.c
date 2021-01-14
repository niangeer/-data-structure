#include <stdio.h>

//给定一个链表，返回链表开始入环的第一个节点。如果链表无环，则返回NULL。
//为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
//如果 pos 是 - 1，则在该链表中没有环。注意，pos 仅仅是用于标识环的情况，并不会作为参数传递到函数中。
//
//说明：不允许修改给定的链表。

//示例1：
//输入：head = [3, 2, 0, -4], pos = 1
//输出：返回索引为 1 的链表节点
//解释：链表中有一个环，其尾部连接到第二个节点。

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head) {
	struct ListNode *slow, *fast;
	slow = fast = head;
	while (fast&&fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow)
		{
			break;
		}
	}
	if (fast == NULL || fast->next == NULL)
	{
		return NULL;
	}
	struct ListNode *meet = fast;
	while (head != meet)
	{
		head = head->next;
		meet = meet->next;
	}
	return meet;
}



