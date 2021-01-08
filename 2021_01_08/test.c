#include <stdio.h>

//1，给定一个头结点为head的非空单链表，返回链表的中间结点。
//   如果有两个中间结点，则返回第二个中间结点。
//
//   示例 1：
//   输入：[1, 2, 3, 4, 5]
//   输出：此列表中的结点 3 (序列化形式：[3, 4, 5])
//   返回的结点值为 3 。(测评系统对该结点序列化表述是[3, 4, 5])。
//   注意，我们返回了一个 ListNode 类型的对象 ans, 这样：
//   ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, 以及 ans.next.next.next = NULL.
//
//   示例 2：
//   输入：[1, 2, 3, 4, 5, 6]
//   输出：此列表中的结点 4 (序列化形式：[4, 5, 6])
//   由于该列表有两个中间结点，值分别为 3 和 4，我们返回第二个结点。   

struct ListNode {
	int val;
	struct ListNode *next;
};

typedef struct ListNode ListNode;
struct ListNode* middleNode(struct ListNode* head){
	ListNode* slow = head, *fast = head;
	//奇数与偶数的循环终止情况
	while (fast && fast->next)
	{
		slow = slow->next;
		//步长为slow两倍，到结尾时slow刚好到中点
		fast = fast->next->next;
	}
	return slow;
}


//2，输入一个链表，输出该链表中倒数第k个结点。
//
//   示例1：
//   输入：1, [1, 2, 3, 4, 5]
//   返回值：[5]

struct ListNode {
	int val;
	struct ListNode *next;
};
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
	struct ListNode* slow = pListHead, *fast = pListHead;
	//先让快指针走K步
	while (k--)
	{
		//K大于链表长度时
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
