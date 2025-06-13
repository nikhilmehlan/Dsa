class Solution {
  public:
    Node* reverseLL(Node* head){
        Node* prev = NULL;
        while(head){
            Node* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    Node* addOne(Node* head) {
        // Step 1: Reverse the linked list
        Node* rh = reverseLL(head);

        // Step 2: Add one to reversed list
        Node* temp = rh;
        int carry = 1;

        while(temp) {
            temp->data += carry;
            if(temp->data < 10) {
                carry = 0;
                break;
            } else {
                temp->data = 0;
                carry = 1;
            }
            if(temp->next == NULL) break;
            temp = temp->next;
        }

        // Step 3: If carry is still left, add new node
        if(carry) {
            temp->next = new Node(1);
        }

        // Step 4: Reverse the list back
        return reverseLL(rh);
    }
};
