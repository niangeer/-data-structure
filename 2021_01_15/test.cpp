#include <stdio.h>
#include <stdbool.h>

//对于一个链表，请设计一个时间复杂度为O(n), 额外空间复杂度为O(1)的算法，判断其是否为回文结构。
//给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900。
//
//测试样例：
//1->2->2->1
//返回：true

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
}; 

//逆置单链表后再进行比较
struct ListNode* reverseList(struct ListNode* head){
	if (NULL == head || NULL == head->next)
	{
		return head;
	}
	struct ListNode* Newhead = NULL, *cur = head, *next = head->next;
	while (cur)
	{
		cur->next = Newhead;
		Newhead = cur;
		cur = next;
		if (next)
			next = next->next;
	}
	return Newhead;
}

class PalindromeList {
public:

	bool chkPalindrome(ListNode* A) {
		ListNode* fast = A;
		ListNode* slow = A;
		ListNode* prev = NULL;
		while (fast&&fast->next)
		{
			prev = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		prev->next = NULL;
		slow = reverseList(slow);
		while (A)
		{
			if (A->val != slow->val)
			{
				return false;
			}
			else
			{
				A = A->next;
				slow = slow->next;
			}
		}
		return true;
	}
};