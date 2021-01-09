#include <stdio.h>

//��������������ϲ�Ϊһ���µ������������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�
//
//ʾ��1��
//
//���룺l1 = [1, 2, 4], l2 = [1, 3, 4]
//�����[1, 1, 2, 3, 4, 4]
//
//ʾ��2��
//
//���룺l1 = [], l2 = []
//�����[]
//
//ʾ��3��
//
//���룺l1 = [], l2 = [0]
//�����[0]

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
	//L1��L2Ϊ��ʱ
	if (NULL == l1)
		return l2;
	if (NULL == l2)
		return l1;
	struct ListNode* head = NULL, *tail = NULL;
	//�Ƚ�һ��val С�Ľڵ�ȡ�£�����β��
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
	//ѭ������������L1��L2����һ��ֵΪNULL
	while (l1 && l2)
	{
		//����β��
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
	//һ��ֻȡ��һ���ڵ㣬����L1��L2�и��ض���Ϊ��
	if (l1)
		tail->next = l1;
	else
		tail->next = l2;
	return head;
}