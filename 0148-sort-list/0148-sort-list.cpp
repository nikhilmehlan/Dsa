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
    ListNode* findmiddle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* mergeList(ListNode* first,ListNode* second){
        ListNode* t1 = first;
ListNode* t2 = second;
ListNode* dNode = new ListNode(-1);
ListNode* temp = dNode;

while (t1 && t2) {
    if (t1->val < t2->val) {
        temp->next = t1;
        temp = t1;
        t1 = t1->next;
    } else {
        temp->next = t2;
        temp = t2;
        t2 = t2->next;
    }
}

if (t1) {
    temp->next = t1;
} else {
    temp->next = t2;
}

return dNode->next;

    }
    
    ListNode* sortList(ListNode* head) {
    if(head==NULL || head->next==NULL) return head;
        ListNode* middle=findmiddle(head);
        ListNode* lefthead=head;
        ListNode* righthead=middle->next;
        middle->next=NULL;
        lefthead=sortList(lefthead);
        righthead=sortList(righthead);
        return mergeList(lefthead,righthead);
    }
};