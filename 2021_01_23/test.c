#include <stdio.h>
#include <stdlib.h>

//��һ�⣺
//����һ������ÿ���ڵ����һ���������ӵ����ָ�룬��ָ�����ָ�������е��κνڵ��սڵ㡣
//Ҫ�󷵻��������������
//������һ���� n ���ڵ���ɵ���������ʾ���� / ����е�����
//ÿ���ڵ���һ��[val, random_index] ��ʾ��
//     val��һ����ʾNode.val ��������
//     random_index�����ָ��ָ��Ľڵ���������Χ�� 0 �� n - 1���������ָ���κνڵ㣬��Ϊ null��
//
//ʾ��1 ��
//���룺head = [[7, null], [13, 0], [11, 4], [10, 2], [1, 0]]
//�����[[7, null], [13, 0], [11, 4], [10, 2], [1, 0]]

//struct Node {
//	int val;
//	struct Node *next;
//	struct Node *random;
//};
//
//typedef struct Node ListNode;
//struct Node* copyRandomList(struct Node* head) {
//	if (NULL == head)
//	{
//		return head;
//	}
//	ListNode* cur = head;
//	//1�������ڵ㣬���ӵ�ԭ����ĺ���
//	while (cur)
//	{
//		//����һ���½ڵ㣬�����г�ʼ��
//		ListNode* copy = (ListNode*)malloc(sizeof(ListNode));
//		copy->next = NULL;
//		copy->random = NULL;
//		copy->val = cur->val;
//		//��ԭ��������ϵ
//		ListNode* Next = cur->next;
//		cur->next = copy;
//		copy->next = Next;
//		//����
//		cur = Next;
//	}
//	//2���������ڵ��random
//	cur = head;
//	while (cur)
//	{
//		ListNode* copy = cur->next;
//		ListNode* Next = copy->next;
//		//�������ڵ��random
//		if (cur->random)
//			copy->random = cur->random->next;
//		else
//			copy->random = NULL;
//
//		cur = Next;
//	}
//	//3������������ԭ�����뿽������
//	cur = head;
//	//���濽�������ͷ���
//	ListNode* copyHead = head->next;
//	while (cur)
//	{
//		ListNode* copy = cur->next;
//		ListNode* Next = copy->next;
//		//��������
//		cur->next = Next;
//		if (Next)
//			copy->next = Next->next;
//		else
//			copy->next = NULL;
//
//		cur = Next;
//	}
//	return copyHead;
//}


//�ڶ��⣺
//��������в�������
//1,���������ǵ����ģ�ÿ��ֻ�ƶ�һ��Ԫ�أ�ֱ������Ԫ�ؿ����γ�һ�����������б�
//2,ÿ�ε����У���������ֻ�������������Ƴ�һ���������Ԫ�أ��ҵ������������ʵ���λ�ã���������롣
//3,�ظ�ֱ�������������ݲ�����Ϊֹ
//
//ʾ��1��
//���� : 4->2->1->3
//��� : 1->2->3->4

//struct ListNode {
//	int val;
//	struct ListNode *next;
//};
//
//typedef struct ListNode ListNode;
//struct ListNode* insertionSortList(struct ListNode* head){
//	//����Ϊ�ջ�Ϊ1ʱֱ�ӷ���ԭ����
//	if (NULL == head || NULL == head->next)
//	{
//		return head;
//	}
//	//��ԭ�����һ���ڵ����µ����������ͷ���
//	ListNode* sortHead = head;
//	ListNode* cur = head->next;
//	sortHead->next = NULL;
//	while (cur)
//	{
//		ListNode *Next = cur->next;
//
//		//��cur���뵽sortHead�����У����ұ�������
//		if (cur->val <= sortHead->val)
//		{
//			//ͷ��
//			cur->next = sortHead;
//			sortHead = cur;
//		}
//		else
//		{
//			//�м��
//			ListNode* sortPrev = sortHead;
//			ListNode* sortCur = sortPrev->next;
//			while (sortCur)
//			{
//				if (cur->val <= sortCur->val)
//				{
//					sortPrev->next = cur;
//					cur->next = sortCur;
//					break;
//				}
//				else
//				{
//					sortPrev = sortCur;
//					sortCur = sortCur->next;
//				}
//			}
//			//β��
//			if (sortCur == NULL)
//			{
//				sortPrev->next = cur;
//				cur->next = NULL;
//			}
//		}
//		cur = Next;
//	}
//	return sortHead;
//}