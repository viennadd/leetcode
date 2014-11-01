class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *p = head;
        while (p && p->next) {
            if (p->val == p->next->val) {

                if (p->next->next)
                    p->next = p->next->next;
                else
                    p->next = NULL;

            } else {
                p = p->next;
            }

        }

        return head;
    }
};