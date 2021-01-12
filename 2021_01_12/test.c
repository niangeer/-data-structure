#include <stdio.h>

//编写一个程序，找到两个单链表相交的起始节点
//
//示例1：
//输入：intersectVal = 8, listA = [4, 1, 8, 4, 5], listB = [5, 0, 1, 8, 4, 5], skipA = 2, skipB = 3;
//输出：Reference of the node with value = 8;
//输入解释：相交节点的值为 8 （注意，如果两个链表相交则不能为 0）。从各自的表头开始算起，链表 A 为[4, 1, 8, 4, 5]，链表 B 为[5, 0, 1, 8, 4, 5]。在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。
//
//注意：
//
//如果两个链表没有交点，返回 null.
//在返回结果后，两个链表仍须保持原有的结构。
//可假定整个链表结构中没有循环。
//程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。


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