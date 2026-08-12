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
        int carry = 0, x, y, sum;
        ListNode dummy(0);
        ListNode *prev = &dummy;
        
        while(l1 or l2) {
            x = l1 ? l1->val : 0;
            y = l2 ? l2->val : 0;
            sum = carry + x + y;
            carry = sum / 10;
            
            prev->next = new ListNode(sum%10);
            prev = prev->next;

            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        if (carry)
            prev->next = new ListNode(carry);
        
        return dummy.next;
    }
};
