/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        unordered_map<Node*, Node*> copyOf; // original -> copy

        // Pass 1: create all copy nodes, no next/random wiring yet
        for (Node* curr = head; curr; curr = curr->next)
            copyOf[curr] = new Node(curr->val);

        // Pass 2: wire up next and random using the map
        for (Node* curr = head; curr; curr = curr->next) {
            copyOf[curr]->next   = curr->next   ? copyOf[curr->next]   : nullptr;
            copyOf[curr]->random = curr->random ? copyOf[curr->random] : nullptr;
        }

        return copyOf[head];
    }
};
