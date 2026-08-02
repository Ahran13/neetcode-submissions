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
        ListNode dummy(0);
        ListNode *node = &dummy;

        while(first and second) {
            if (first->val < second->val) {
                node->next = first;
                node = first;
                first = first->next;
            }
            else {
                node->next = second;
                node = second;
                second = second->next;
            }
        }

        (first) ? node->next = first : node->next = second;
        return dummy.next;
    }
};
