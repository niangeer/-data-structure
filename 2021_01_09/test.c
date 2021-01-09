#include <stdio.h>

//将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
//
//示例1：
//
//输入：l1 = [1, 2, 4], l2 = [1, 3, 4]
//输出：[1, 1, 2, 3, 4, 4]
//
//示例2：
//
//输入：l1 = [], l2 = []
//输出：[]
//
//示例3：
//
//输入：l1 = [], l2 = [0]
//输出：[0]

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
	//L1或L2为空时
	if (NULL == l1)
		return l2;
	if (NULL == l2)
		return l1;
	struct ListNode* head = NULL, *tail = NULL;
	//先将一个val 小的节点取下，方便尾插
	if (l1->val<l2->val)
	{
		head = tail = l1;
		l1 = l1->next;
	}
	else
	{
		head = tail = l2;
		l2 = l2->next;
	}
	//循环结束条件，L1与L2其中一个值为NULL
	while (l1 && l2)
	{
		//进行尾插
		if (l1->val<l2->val)
		{
			tail->next = l1;
			l1 = l1->next;
		}
		else
		{
			tail->next = l2;
			l2 = l2->next;
		}
		tail = tail->next;
	}
	//一次只取下一个节点，所以L1与L2有个必定不为空
	if (l1)
		tail->next = l1;
	else
		tail->next = l2;
	return head;
}