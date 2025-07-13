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
    ListNode* deleteDuplicates(ListNode* head) {
     //empty list
     if(head == NULL)
     return NULL;   
     ListNode* curr = head;
    
    while(curr != NULL){
        if((curr -> next != NULL) && (curr -> val == curr -> next -> val)){
            ListNode* nextNext = curr -> next ->next;
            ListNode* nodeDelete = curr ->next;
            delete(nodeDelete);
            curr -> next = nextNext;
        }
        else{
            curr = curr -> next;
        }
    }
    return head;
    }
};