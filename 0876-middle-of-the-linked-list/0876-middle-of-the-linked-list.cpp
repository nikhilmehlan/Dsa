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
    ListNode* middleNode(ListNode* head) {
        int len=0;
        ListNode* temp=head;
        while(temp){
            len++;
            temp=temp->next;
        }
        int find;
        if(len%2!=0){
            find=(len/2)+1;
        }
        else{
            find=(len/2)+1;
        }
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            return head;
        }
        int cnt=0;
        temp=head;
        while(temp){
            cnt++;
            if(cnt==find) break;
            temp=temp->next;
        }
        return temp;
    }
};