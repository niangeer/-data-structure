#include <stdio.h>
#include <stdbool.h>

//����һ�����������һ��ʱ�临�Ӷ�ΪO(n), ����ռ临�Ӷ�ΪO(1)���㷨���ж����Ƿ�Ϊ���Ľṹ��
//����һ�������ͷָ��A���뷵��һ��boolֵ���������Ƿ�Ϊ���Ľṹ����֤������С�ڵ���900��
//
//����������
//1->2->2->1
//���أ�true

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
}; 

//���õ�������ٽ��бȽ�
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