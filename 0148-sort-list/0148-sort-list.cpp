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
    ListNode* sortList(ListNode* head) {
        vector<int> temp;
        ListNode* use=head;
        while(use){
            temp.push_back(use->val);
            use=use->next;
        }
        use=head;
        sort(temp.begin(),temp.end());
        int i=0;
        while(use){
            use->val=temp[i++];
            use=use->next;
        }
        return head;
    }
};