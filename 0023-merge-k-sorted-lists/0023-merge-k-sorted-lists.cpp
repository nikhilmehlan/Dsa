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
        return a->val > b->val;  // Min-heap (smallest element at top)
    }
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
     priority_queue<ListNode*,vector<ListNode*>,Compare> pq;
        for(ListNode* list:lists){
            if(list) pq.push(list);
        }

        ListNode* dummy=new ListNode(0);
        ListNode* tail=dummy;

        while(!pq.empty()){
            ListNode* node=pq.top();
            pq.pop();
            tail->next=node;
            tail=node;

            if(node->next){
                pq.push(node->next);
            }
        }
        return dummy->next;
    }
};