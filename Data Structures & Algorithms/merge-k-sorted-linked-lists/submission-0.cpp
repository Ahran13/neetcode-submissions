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
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> currs = lists;
        int k = lists.size();

        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        for (ListNode* head : lists)
            if (head != nullptr)
                pq.push(head);

        if (pq.empty())
            return nullptr;

        ListNode* head = pq.top();
        ListNode* tail = head;

        while(!pq.empty())
        {
            ListNode* curr = pq.top();
            if(curr->next)
                pq.push(curr->next);
            pq.pop();

            tail->next = curr;
            tail = curr;
        }
        return head;
    }
};
