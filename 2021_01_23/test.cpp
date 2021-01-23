#include <stdio.h>
#include <stdlib.h>

//第三题
//在一个排序的链表中，存在重复的结点，
//请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
//例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
//示例1：
//输入
//{ 1, 2, 3, 3, 4, 4, 5 }
//返回值
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
		//链表为空或者为1 时
		if (pHead == NULL || pHead->next == NULL)
			return pHead;
		//定义前中后三个指针
		ListNode *prev = NULL, *cur = pHead, *next = pHead->next;

		while (next)
		{
			//不重复的情况
			if (cur->val != next->val)
			{
				prev = cur;
				cur = next;
				next = next->next;
			}
			//重复的情况
			else
			{
				//让next指针一直走到与cur不重复的地方
				while (next&&cur->val == next->val)
				{
					next = next->next;
				}
				//重复的情况可能在头结点处，此时prev为NULL
				if (prev == NULL)
				{
					pHead = next;
				}
				else
				{
					prev->next = next;
				}

				//将重复的指针进行释放
				while (cur != next)
				{
					ListNode* del = cur;
					cur = cur->next;
					free(del);
				}
				//当重复情况在链表尾节点时，此时cur会为NULL
				if (cur)
					next = cur->next;
			}
		}
		return pHead;
	}
};