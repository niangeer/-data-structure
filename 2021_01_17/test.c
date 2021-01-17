#include <stdio.h>
#include <stdlib.h>

//对链表进行插入排序。
//1,插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
//2,每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
//3,重复直到所有输入数据插入完为止
//
//示例1：
//输入 : 4->2->1->3
//输出 : 1->2->3->4

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

		//把cur插入到sortHead链表中，并且保持有序
		if (cur->val <= sortHead->val)
		{
			//头插
			cur->next = sortHead;
			sortHead = cur;
		}
		else
		{
			//中间插
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
			//尾插
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