#include <stdio.h>

//����һ��������������ʼ�뻷�ĵ�һ���ڵ㡣��������޻����򷵻�NULL��
//Ϊ�˱�ʾ���������еĻ�������ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ����
//��� pos �� - 1�����ڸ�������û�л���ע�⣬pos ���������ڱ�ʶ�����������������Ϊ�������ݵ������С�
//
//˵�����������޸ĸ���������

//ʾ��1��
//���룺head = [3, 2, 0, -4], pos = 1
//�������������Ϊ 1 ������ڵ�
//���ͣ���������һ��������β�����ӵ��ڶ����ڵ㡣

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head) {
	struct ListNode *slow, *fast;
	slow = fast = head;
	while (fast&&fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow)
		{
			break;
		}
	}
	if (fast == NULL || fast->next == NULL)
	{
		return NULL;
	}
	struct ListNode *meet = fast;
	while (head != meet)
	{
		head = head->next;
		meet = meet->next;
	}
	return meet;
}



