#include <stdio.h>

//��дһ�������ҵ������������ཻ����ʼ�ڵ�
//
//ʾ��1��
//���룺intersectVal = 8, listA = [4, 1, 8, 4, 5], listB = [5, 0, 1, 8, 4, 5], skipA = 2, skipB = 3;
//�����Reference of the node with value = 8;
//������ͣ��ཻ�ڵ��ֵΪ 8 ��ע�⣬������������ཻ����Ϊ 0�����Ӹ��Եı�ͷ��ʼ�������� A Ϊ[4, 1, 8, 4, 5]������ B Ϊ[5, 0, 1, 8, 4, 5]���� A �У��ཻ�ڵ�ǰ�� 2 ���ڵ㣻�� B �У��ཻ�ڵ�ǰ�� 3 ���ڵ㡣
//
//ע�⣺
//
//�����������û�н��㣬���� null.
//�ڷ��ؽ���������������뱣��ԭ�еĽṹ��
//�ɼٶ���������ṹ��û��ѭ����
//���������� O(n) ʱ�临�Ӷȣ��ҽ��� O(1) �ڴ档


 struct ListNode {
	int val;
	struct ListNode *next;
};

typedef struct ListNode ListNode;
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	ListNode* curA = headA;
	int la = 0;
	while (curA)
	{
		curA = curA->next;
		++la;
	}
	ListNode* curB = headB;
	int  lb = 0;
	while (curB)
	{
		curB = curB->next;
		++lb;
	}
	ListNode* longList = headA;
	ListNode* shortList = headB;
	if (lb>la)
	{
		longList = headB;
		shortList = headA;
	}
	int gap = abs(la - lb);
	while (gap--)
	{
		longList = longList->next;
	}
	while (longList)
	{
		if (longList == shortList)
		{
			return longList;
		}
		longList = longList->next;
		shortList = shortList->next;
	}
	return NULL;
}