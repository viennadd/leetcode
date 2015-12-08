//
// Created by vienna on 7/12/2015.
//

#ifndef LEETCODE_ADD_TWO_NUMBERS_H
#define LEETCODE_ADD_TWO_NUMBERS_H


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
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result;
        ListNode *p;

        int a, b, sum;
        bool overflow = false;

        if (!l1 && !l2) {
            result->val = 0;
            return result;
        } else {

            if (l1) {
                a = l1->val;
                l1 = l1->next;
            } else {
                a = 0;
            }

            if (l2) {
                b = l2->val;
                l2 = l2->next;
            } else {
                b = 0;
            }

            sum = a + b;
            overflow = sum >= 10;
            sum = overflow ? sum % 10 : sum;

            result = new ListNode(sum);
            p = result;
        }



        while (l1 || l2) {

            if (l1) {
                a = l1->val;
                l1 = l1->next;
            } else {
                a = 0;
            }

            if (l2) {
                b = l2->val;
                l2 = l2->next;
            } else {
                b = 0;
            }

            sum = a + b + (overflow ? 1 : 0);
            overflow = sum >= 10;

            sum = overflow ? sum % 10 : sum;

            p->next = new ListNode(sum);
            p = p->next;
        }

        if (overflow) {
            p->next = new ListNode(1);
            p = p->next;
        }

        return result;
    }

};

#endif //LEETCODE_ADD_TWO_NUMBERS_H
