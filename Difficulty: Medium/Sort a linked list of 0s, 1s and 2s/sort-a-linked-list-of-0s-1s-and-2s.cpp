class Solution {
  public:
    Node* segregate(Node* head) {
        // Dummy nodes for 0s, 1s and 2s
        Node* zero = new Node(-1);
        Node* one = new Node(-1);
        Node* two = new Node(-1);
        
        Node* zhead = zero;
        Node* ohead = one;
        Node* thead = two;
        Node* temp = head;
        
        while (temp) {
            if (temp->data == 0) {
                zhead->next = temp;
                zhead = temp;
            }
            else if (temp->data == 1) {
                ohead->next = temp;
                ohead = temp;
            }
            else {
                thead->next = temp;
                thead = temp;
            }
            temp = temp->next;
        }
        
        // Connect the lists: 0s -> 1s -> 2s
        zhead->next = one->next ? one->next : two->next;
        ohead->next = two->next;
        thead->next = NULL;
        
        Node* newHead = zero->next;

        // Free dummy nodes (optional in interview setting)
        delete zero;
        delete one;
        delete two;

        return newHead;
    }
};
