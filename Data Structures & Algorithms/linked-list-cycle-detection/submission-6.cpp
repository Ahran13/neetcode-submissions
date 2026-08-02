/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode *p, *q;
        p = q = head;
        if (!head or !head->next)
            return false;
        while(p and q) {
            p = p->next;
            q = q->next;
            q!=NULL ? q = q->next : q = nullptr;

            if(q == p)
                return true;
        }
        return false;
    }
};
