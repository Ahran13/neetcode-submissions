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
        ListNode *last, *head2 = NULL, *head1, *curr, *node; 
        last = curr = node = head;

        head1 = head->next;
        
        while(last) {
            last = last->next;
            n++;
        }

        if (n < 3) return;
        n = (n+1)/2;

        for(int i = 0; i < n - 1; i++) 
            curr = curr->next;
        
        head2 = curr->next; 
        curr->next = NULL; 
        
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
