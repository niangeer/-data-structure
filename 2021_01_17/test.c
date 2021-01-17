#include <stdio.h>
#include <stdlib.h>

//��������в�������
//1,���������ǵ����ģ�ÿ��ֻ�ƶ�һ��Ԫ�أ�ֱ������Ԫ�ؿ����γ�һ�����������б�
//2,ÿ�ε����У���������ֻ�������������Ƴ�һ���������Ԫ�أ��ҵ������������ʵ���λ�ã���������롣
//3,�ظ�ֱ�������������ݲ�����Ϊֹ
//
//ʾ��1��
//���� : 4->2->1->3
//��� : 1->2->3->4

struct ListNode {
	int val;
	struct ListNode *next;
};


typedef struct ListNode ListNode;
struct ListNode* insertionSortList(struct ListNode* head){
	if (NULL == head || NULL == head->next)
	{
		return head;
	}
	ListNode *sortHead = head;
	ListNode *cur = head->next;
	sortHead->next = NULL;
	while (cur)
	{
		ListNode *Next = cur->next;

		//��cur���뵽sortHead�����У����ұ�������
		if (cur->val <= sortHead->val)
		{
			//ͷ��
			cur->next = sortHead;
			sortHead = cur;
		}
		else
		{
			//�м��
			ListNode* sortPrev = sortHead;
			ListNode* sortCur = sortPrev->next;
			while (sortCur)
			{
				if (cur->val <= sortCur->val)
				{
					sortPrev->next = cur;
					cur->next = sortCur;
					break;
				}
				else
				{
					sortPrev = sortCur;
					sortCur = sortCur->next;
				}
			}
			//β��
			if (sortCur == NULL)
			{
				sortPrev->next = cur;
				cur->next = NULL;
			}
		}
		cur = Next;
	}
	return sortHead;
}