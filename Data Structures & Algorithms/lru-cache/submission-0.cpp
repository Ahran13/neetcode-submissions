#include <unordered_map>
using namespace std;

class Node {
public:
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int key, int value) {
        this->key = key;
        this->value = value;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
    unordered_map<int, Node*> cache;
    int capacity;
    Node* head = nullptr;  // MRU
    Node* tail = nullptr;  // LRU

    // Unlink a node from the list (does not touch the map or delete it)
    void unlink(Node* node) {
        if (node->prev)
            node->prev->next = node->next;
        else
            head = node->next;

        if (node->next)
            node->next->prev = node->prev;
        else
            tail = node->prev;
    }

    // Insert a node at the head of the list
    void insertAtHead(Node* node) {
        node->prev = nullptr;
        node->next = head;

        if (head)
            head->prev = node;
        else
            tail = node;

        head = node;
    }

    void shiftToHead(Node* node) {
        unlink(node);
        insertAtHead(node);
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end())
            return -1;

        Node* node = it->second;
        shiftToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        auto it = cache.find(key);

        // Case 1: key already exists -> just update value & move to head
        if (it != cache.end()) {
            it->second->value = value;
            shiftToHead(it->second);
            return;
        }

        // Case 2: at capacity -> evict the LRU (tail) node first
        if ((int)cache.size() >= capacity) {
            Node* lru = tail;
            unlink(lru);
            cache.erase(lru->key);
            delete lru;
        }

        // Case 3: insert the new node at head
        Node* node = new Node(key, value);
        cache[key] = node;
        insertAtHead(node);
    }

    ~LRUCache() {
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
};