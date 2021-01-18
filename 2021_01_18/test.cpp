#include <stdio.h>
#include <stdlib.h>

//��һ������������У������ظ��Ľ�㣬
//��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ�롣
//���磬����1->2->3->3->4->4->5 ������Ϊ 1->2->5
//ʾ��1��
//����
//{ 1, 2, 3, 3, 4, 4, 5 }
//����ֵ
//{ 1, 2, 5 }

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == NULL || pHead->next == NULL)
			return pHead;
		ListNode *prev = NULL, *cur = pHead, *next = pHead->next;
		while (next)
		{
			if (cur->val != next->val)
			{
				prev = cur;
				cur = next;
				next = next->next;
			}
			else
			{
				while (next&&cur->val == next->val)
				{
					next = next->next;
				}
				if (prev == NULL)
				{
					pHead = next;
				}
				else
				{
					prev->next = next;
				}
				//�ͷ�
				while (cur != next)
				{
					ListNode* del = cur;
					cur = cur->next;
					free(del);
				}
				if (cur)
					next = cur->next;
			}
		}
		return pHead;
	}
};