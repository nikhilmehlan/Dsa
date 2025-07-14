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
    int getDecimalValue(ListNode* head) {
        vector<int> temp;
        while(head){
            temp.push_back(head->val);
            head=head->next;
        }
        int num=0;
        for(int i=temp.size()-1;i>=0;i--){
            num+=(temp[temp.size()-i-1]*pow(2,i));
        }
        return num;
    }
};