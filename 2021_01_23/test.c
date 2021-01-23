#include <stdio.h>
#include <stdlib.h>

//第一题：
//给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
//要求返回这个链表的深拷贝。
//我们用一个由 n 个节点组成的链表来表示输入 / 输出中的链表。
//每个节点用一个[val, random_index] 表示：
//     val：一个表示Node.val 的整数。
//     random_index：随机指针指向的节点索引（范围从 0 到 n - 1）；如果不指向任何节点，则为 null。
//
//示例1 ：
//输入：head = [[7, null], [13, 0], [11, 4], [10, 2], [1, 0]]
//输出：[[7, null], [13, 0], [11, 4], [10, 2], [1, 0]]

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
//	//1，拷贝节点，链接到原链表的后面
//	while (cur)
//	{
//		//创建一个新节点，并进行初始化
//		ListNode* copy = (ListNode*)malloc(sizeof(ListNode));
//		copy->next = NULL;
//		copy->random = NULL;
//		copy->val = cur->val;
//		//与原链表建立联系
//		ListNode* Next = cur->next;
//		cur->next = copy;
//		copy->next = Next;
//		//迭代
//		cur = Next;
//	}
//	//2，处理拷贝节点的random
//	cur = head;
//	while (cur)
//	{
//		ListNode* copy = cur->next;
//		ListNode* Next = copy->next;
//		//处理拷贝节点的random
//		if (cur->random)
//			copy->random = cur->random->next;
//		else
//			copy->random = NULL;
//
//		cur = Next;
//	}
//	//3，将链表分离成原链表与拷贝链表
//	cur = head;
//	//保存拷贝链表的头结点
//	ListNode* copyHead = head->next;
//	while (cur)
//	{
//		ListNode* copy = cur->next;
//		ListNode* Next = copy->next;
//		//分离链表
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


//第二题：
//对链表进行插入排序。
//1,插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
//2,每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
//3,重复直到所有输入数据插入完为止
//
//示例1：
//输入 : 4->2->1->3
//输出 : 1->2->3->4

//struct ListNode {
//	int val;
//	struct ListNode *next;
//};
//
//typedef struct ListNode ListNode;
//struct ListNode* insertionSortList(struct ListNode* head){
//	//链表为空或为1时直接返回原链表
//	if (NULL == head || NULL == head->next)
//	{
//		return head;
//	}
//	//将原链表第一个节点拿下当成新链表的头结点
//	ListNode* sortHead = head;
//	ListNode* cur = head->next;
//	sortHead->next = NULL;
//	while (cur)
//	{
//		ListNode *Next = cur->next;
//
//		//把cur插入到sortHead链表中，并且保持有序
//		if (cur->val <= sortHead->val)
//		{
//			//头插
//			cur->next = sortHead;
//			sortHead = cur;
//		}
//		else
//		{
//			//中间插
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
//			//尾插
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