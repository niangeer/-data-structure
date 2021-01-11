#include <stdio.h>
#include <stdlib.h>

//现有一链表的头指针 ListNode* pHead，给一定值x，编写一段代码将所有小于x的结点排在其余结点之前，
//且不能改变原来的数据顺序，返回重新排列后的链表的头指针。
//例1：
//4, [1,9,3,5,6,7,2,4]
//返回[1,3,2,9,5,6,7,4]

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
		//创建两条新链表，将小于x的尾插入lesstail;其它的尾插入greatertail;
		ListNode* lesshead = NULL, *lesstail = NULL;
		ListNode* greaterhead = NULL, *greatertail = NULL;
		lesshead = lesstail = (ListNode*)malloc(sizeof(ListNode));
		greaterhead = greatertail = (ListNode*)malloc(sizeof(ListNode));
		lesshead->next = greaterhead->next = NULL;
		//循环结束条件：遍历完链表
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
		//当最后一个大于x的结点后面还跟着小于x的结点时，会形成回环，所以置空
		greatertail->next = NULL;
		//将大于等于x的链表尾插在小于x链表的后面
		lesstail->next = greaterhead->next;
		ListNode* List = lesshead->next;
		//释放内存
		free(lesshead);
		free(greaterhead);
		return List;
	}
};