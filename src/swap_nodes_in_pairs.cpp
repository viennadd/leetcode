
/*
Swap Nodes in Pairs

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
private:
	ListNode* swap(ListNode *node, ListNode *prev)
	{
		/*
			node->second->after_next
			=> second->node->after_next
			=> previous->second->node->after_next
		*/
		ListNode *second = node->next;
		ListNode *after_next = second->next;

		node->next = after_next;
		second->next = node;

		if (prev)
			prev->next = second;

		return node;
	}

public:
	ListNode *swapPairs(ListNode *head) {

		ListNode *ret;
		ListNode *prev = nullptr;

		/* handle empty list */
		if (!head)
			return head;

		/* handle single element */
		if (head->next)
			ret = head->next;
		else
			ret = head;

		while (head && head->next) {
			prev = swap(head, prev);
			head = prev->next;
		}

		return ret;
	}
};
