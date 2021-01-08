#include <stdio.h>

//1������һ��ͷ���Ϊhead�ķǿյ���������������м��㡣
//   ����������м��㣬�򷵻صڶ����м��㡣
//
//   ʾ�� 1��
//   ���룺[1, 2, 3, 4, 5]
//   ��������б��еĽ�� 3 (���л���ʽ��[3, 4, 5])
//   ���صĽ��ֵΪ 3 ��(����ϵͳ�Ըý�����л�������[3, 4, 5])��
//   ע�⣬���Ƿ�����һ�� ListNode ���͵Ķ��� ans, ������
//   ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, �Լ� ans.next.next.next = NULL.
//
//   ʾ�� 2��
//   ���룺[1, 2, 3, 4, 5, 6]
//   ��������б��еĽ�� 4 (���л���ʽ��[4, 5, 6])
//   ���ڸ��б��������м��㣬ֵ�ֱ�Ϊ 3 �� 4�����Ƿ��صڶ�����㡣   

struct ListNode {
	int val;
	struct ListNode *next;
};

typedef struct ListNode ListNode;
struct ListNode* middleNode(struct ListNode* head){
	ListNode* slow = head, *fast = head;
	//������ż����ѭ����ֹ���
	while (fast && fast->next)
	{
		slow = slow->next;
		//����Ϊslow����������βʱslow�պõ��е�
		fast = fast->next->next;
	}
	return slow;
}


//2������һ����������������е�����k����㡣
//
//   ʾ��1��
//   ���룺1, [1, 2, 3, 4, 5]
//   ����ֵ��[5]

struct ListNode {
	int val;
	struct ListNode *next;
};
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
	struct ListNode* slow = pListHead, *fast = pListHead;
	//���ÿ�ָ����K��
	while (k--)
	{
		//K����������ʱ
		if (NULL == fast)
		{
			return NULL;
		}
		fast = fast->next;
	}
	while (fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}
