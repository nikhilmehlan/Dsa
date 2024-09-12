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
    ListNode* findlast(ListNode* temp,int k){
     int cnt=1;
     while(temp){
          if(cnt==k) return temp;
          cnt++;
          temp=temp->next;
     }
     return temp;
}
    ListNode* rotateRight(ListNode* head, int k) {
      if(head==NULL || k==0) return head;
     ListNode* temp=head;
     int len=1;
     while(temp->next){
          len++;
          temp=temp->next;
     }
     if(k%len==0) return head;
     k=k%len;
     temp->next=head;
     ListNode* newLast=findlast(head,len-k);
     head=newLast->next;
     newLast->next=NULL;
     return head;   
    }
};