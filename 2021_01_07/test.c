#include <stdio.h>

//��תһ��������
//
//ʾ�� :
//���� : 1->2->3->4->5->NULL
//��� : 5->4->3->2->1->NULL

struct ListNode {
	int val;
	struct ListNode *next;
};

//����һ��
struct ListNode* reverseList(struct ListNode* head){
	if (NULL == head || NULL == head->next)
	{
		return head;
	}
	struct ListNode* n1 = NULL, *n2 = head, *n3 = head->next;
	while (n3)
	{
		//��ת
		n2->next = n1;
		//����
		n1 = n2;
		n2 = n3;
		n3 = n3->next;
	}
	n2->next = n1;
	return n2;
}


//��������
struct ListNode* reverseList(struct ListNode* head){
	if (NULL == head || NULL == head->next)
	{
		return head;
	}
	struct ListNode* Newhead = NULL, *cur = head, *next = head->next;
	while (cur)
	{
		//ͷ��
		cur->next = Newhead;
		Newhead = cur;
		//����
		cur = next;
		if (next)
			next = next->next;
	}
	return Newhead;
}