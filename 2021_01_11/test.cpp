#include <stdio.h>
#include <stdlib.h>

//����һ�����ͷָ�� ListNode* pHead����һ��ֵx����дһ�δ��뽫����С��x�Ľ������������֮ǰ��
//�Ҳ��ܸı�ԭ��������˳�򣬷����������к�������ͷָ�롣
//��1��
//4, [1,9,3,5,6,7,2,4]
//����[1,3,2,9,5,6,7,4]

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
}; 

typedef struct ListNode ListNode;
class Partition {
public:
	ListNode* partition(ListNode* pHead, int x) {
		ListNode* cur = pHead;
		//����������������С��x��β����lesstail;������β����greatertail;
		ListNode* lesshead = NULL, *lesstail = NULL;
		ListNode* greaterhead = NULL, *greatertail = NULL;
		lesshead = lesstail = (ListNode*)malloc(sizeof(ListNode));
		greaterhead = greatertail = (ListNode*)malloc(sizeof(ListNode));
		lesshead->next = greaterhead->next = NULL;
		//ѭ����������������������
		while (cur)
		{
			if (cur->val<x)
			{
				lesstail->next = cur;
				lesstail = lesstail->next;
			}
			else
			{
				greatertail->next = cur;
				greatertail = greatertail->next;
			}
			cur = cur->next;
		}
		//�����һ������x�Ľ����滹����С��x�Ľ��ʱ�����γɻػ��������ÿ�
		greatertail->next = NULL;
		//�����ڵ���x������β����С��x����ĺ���
		lesstail->next = greaterhead->next;
		ListNode* List = lesshead->next;
		//�ͷ��ڴ�
		free(lesshead);
		free(greaterhead);
		return List;
	}
};