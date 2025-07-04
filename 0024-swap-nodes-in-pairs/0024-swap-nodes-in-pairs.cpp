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
    void swap(ListNode* a,ListNode* b){
        int temp=a->val;
        a->val=b->val;
        b->val=temp;
    }
    ListNode* swapPairs(ListNode* head) {
        ListNode* node=head;
        while(node && node->next){
            swap(node,node->next);
            if(node->next->next) node=node->next->next;
            else break;
        }
        return head;
    }
};