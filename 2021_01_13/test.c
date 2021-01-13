#include <stdio.h>
#include <stdbool.h>

//����һ�������ж��������Ƿ��л��������������ĳ���ڵ㣬����ͨ���������� next ָ���ٴε���������д��ڻ���
//Ϊ�˱�ʾ���������еĻ�������ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ����
//��� pos �� - 1�����ڸ�������û�л���ע�⣺pos ����Ϊ�������д��ݣ�������Ϊ�˱�ʶ�����ʵ�������
//��������д��ڻ����򷵻� true �� ���򣬷��� false ��
//�� O(1)�������������ڴ��������⡣
//ʾ��1 ��
//���룺head = [3, 2, 0, -4], pos = 1
//�����true
//���ͣ���������һ��������β�����ӵ��ڶ����ڵ㡣

struct ListNode {
	int val;
	struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
	struct ListNode *slow = head;
	struct ListNode *fast = head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			return true;
		}
	}
	return false;
}
