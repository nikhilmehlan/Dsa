/*
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    // Function to find the length of a loop in the linked .
    int countNodesinLoop(Node *head) {
        // Code here
        Node* slow=head;
        Node* fast=head;
        int cnt=1;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                int cnt=1;
                Node* temp=slow->next;
                while(temp!=slow){
                    cnt++;
                    temp=temp->next;
                }
                return cnt;
            }}
            return 0;
    }
};