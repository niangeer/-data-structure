#include <stdio.h>

//反转一个单链表。
//
//示例 :
//输入 : 1->2->3->4->5->NULL
//输出 : 5->4->3->2->1->NULL

struct ListNode {
	int val;
	struct ListNode *next;
};

//方法一：
struct ListNode* reverseList(struct ListNode* head){
	if (NULL == head || NULL == head->next)
	{
		return head;
	}
	struct ListNode* n1 = NULL, *n2 = head, *n3 = head->next;
	while (n3)
	{
		//反转
		n2->next = n1;
		//迭代
		n1 = n2;
		n2 = n3;
		n3 = n3->next;
	}
	n2->next = n1;
	return n2;
}


//方法二：
struct ListNode* reverseList(struct ListNode* head){
	if (NULL == head || NULL == head->next)
	{
		return head;
	}
	struct ListNode* Newhead = NULL, *cur = head, *next = head->next;
	while (cur)
	{
		//头插
		cur->next = Newhead;
		Newhead = cur;
		//迭代
		cur = next;
		if (next)
			next = next->next;
	}
	return Newhead;
}