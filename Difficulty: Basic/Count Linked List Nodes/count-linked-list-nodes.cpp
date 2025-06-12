/* Link list node */
/*
struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
}; */

class Solution {
  public:
    // Function to count nodes of a linked list.
    int getCount(struct Node* head) {

        // Code here
        if(head==NULL) return 0;
        if(head->next==NULL) return 1;
        int cnt=0;
        while(head){
            cnt++;
            head=head->next;
        }
        return cnt;
    }
};