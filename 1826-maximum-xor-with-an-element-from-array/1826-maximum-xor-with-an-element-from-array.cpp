#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class TrieNode {
public:
    TrieNode* children[2];
    TrieNode() {
        children[0] = children[1] = nullptr;
    }
};

class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }

    void insert(int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (!node->children[bit])
                node->children[bit] = new TrieNode();
            node = node->children[bit];
        }
    }

    int getMaxXOR(int num) {
        TrieNode* node = root;
        if (!node->children[0] && !node->children[1])
            return -1; // empty trie

        int maxXor = 0;
        for (int i = 31; i >= 0; --i) {
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
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        int n = queries.size();
        
        vector<vector<int>> offlineQueries; // [xi, mi, index]
        for (int i = 0; i < n; ++i) {
            offlineQueries.push_back({queries[i][0], queries[i][1], i});
        }

        sort(offlineQueries.begin(), offlineQueries.end(), [](auto &a, auto &b) {
            return a[1] < b[1]; // sort by mi
        });

        vector<int> result(n, -1);
        Trie trie;
        int idx = 0;
        for (auto &q : offlineQueries) {
            int x = q[0], m = q[1], qIdx = q[2];

            // Insert eligible nums into trie
            while (idx < nums.size() && nums[idx] <= m) {
                trie.insert(nums[idx]);
                idx++;
            }

            // If trie is not empty, compute max XOR
            result[qIdx] = trie.getMaxXOR(x);
        }

        return result;
    }
};
