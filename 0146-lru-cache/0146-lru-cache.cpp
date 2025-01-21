#include <unordered_map>
using namespace std;

class LRUCache {
public:
    class node {
    public:
        int key;
        int val;
        node* next;
        node* prev;

        node(int _key, int _val) {
            key = _key;
            val = _val;
            next = nullptr;
            prev = nullptr;
        }
    };

    node* head;
    node* tail;
    int cap;
    unordered_map<int, node*> m;

    LRUCache(int capacity) {
        cap = capacity;

        // Initialize dummy head and tail nodes
        head = new node(-1, -1);
        tail = new node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    void addnode(node* newnode) {
        // Add node right after the head
        newnode->next = head->next;
        newnode->prev = head;

        head->next->prev = newnode;
        head->next = newnode;
    }

    void deletenode(node* delnode) {
        // Remove a node from the linked list
        node* delprev = delnode->prev;
        node* delnext = delnode->next;

        delprev->next = delnext;
        delnext->prev = delprev;
    }

    int get(int key) {
        if (m.find(key) != m.end()) {
            node* resnode = m[key];
            int res = resnode->val;

            // Move the accessed node to the front
            deletenode(resnode);
            addnode(resnode);

            return res;
        }
        return -1; // Key not found
    }

    void put(int key, int value) {
        // If the key already exists, update the value and move it to the front
        if (m.find(key) != m.end()) {
            node* existingnode = m[key];
            m.erase(key);
            deletenode(existingnode);
        }

        // If the cache is full, remove the least recently used (LRU) node
        if (m.size() == cap) {
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }

        // Add the new node and update the map
        node* newnode = new node(key, value);
        addnode(newnode);
        m[key] = newnode;
    }
};
