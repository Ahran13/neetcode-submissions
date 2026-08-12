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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, x, y;
        int sum = 0;
        ListNode *res = new ListNode();
        ListNode dummy(0);
        ListNode *prev = &dummy;
        prev->next = res;
        
        while(l1 or l2) {
            l1 ? x = l1->val: x = 0;
            l2 ? y = l2->val: y = 0;
            sum = carry + x + y;
            carry = 0;
            if(sum > 9) 
                carry = 1;
            
            ListNode* t = new ListNode(sum%10);
            res->next = t;
            res = t;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        if (carry) {
            ListNode* t = new ListNode(1);
            res->next = t;
            res = t;
        }
        return dummy.next->next;
    }
};
