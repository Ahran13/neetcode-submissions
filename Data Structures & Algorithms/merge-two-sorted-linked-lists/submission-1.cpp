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
    ListNode* mergeTwoLists(ListNode* first, ListNode* second) {
        ListNode *last, *third;
        if(!first)
            return second;
        else if(!second)
            return first;
        if (first->val < second->val) {
                third = last = first;
                first = first->next;
                last->next = nullptr;
            }
            else {
                third = last = second;
                second = second->next;
                last->next = nullptr;
            }

        while(first and second) {
            if (first->val < second->val) {
                last->next = first;
                last = first;
                first = first->next;
                last->next = nullptr;
            }
            else {
                last->next = second;
                last = second;
                second = second->next;
                last->next = nullptr;
            }
        }

        if (first) 
            last->next = first;
        else
            last->next = second;
    
        return third;
    }
};
