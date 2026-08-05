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
    ListNode* reverseList(ListNode* head) {
        ListNode* r = nullptr;
        ListNode* q = nullptr;

        while(head) {
            r = q;
            q = head;
            head = head->next;
            q->next = r;
        }
        return q;
    }

    void reorderList(ListNode* head) {
        int n = 0;
        ListNode *fast, *head2 = NULL, *head1, *slow, *node; 
        slow = fast = node = head;

        head1 = head->next;
        
        while(fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        head2 = slow->next;
        slow->next = NULL; 
        
        head2 = reverseList(head2);
        
        while(head2) {
            node->next = head2;
            node = head2;
            head2 = head2->next;

            if (head1) {
                node->next = head1;
                node = head1;
                head1 = head1->next;
            }
        }
    }
};
