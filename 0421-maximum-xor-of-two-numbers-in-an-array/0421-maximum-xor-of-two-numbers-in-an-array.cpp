#include <vector>
#include <iostream>
using namespace std;

class TrieNode {
public:
    TrieNode* children[2]; // 0 or 1

    TrieNode() {
        children[0] = nullptr;
        children[1] = nullptr;
    }
};

class Solution {
public:
    void insert(TrieNode* root, int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->children[bit])
                node->children[bit] = new TrieNode();
            node = node->children[bit];
        }
    }

    int getMaxXOR(TrieNode* root, int num) {
        TrieNode* node = root;
        int maxXor = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int toggledBit = 1 - bit;
            if (node->children[toggledBit]) {
                maxXor |= (1 << i);
                node = node->children[toggledBit];
            } else {
                node = node->children[bit];
            }
        }
        return maxXor;
    }

    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();
        for (int num : nums) {
            insert(root, num);
        }

        int maxResult = 0;
        for (int num : nums) {
            maxResult = max(maxResult, getMaxXOR(root, num));
        }
        return maxResult;
    }
};
