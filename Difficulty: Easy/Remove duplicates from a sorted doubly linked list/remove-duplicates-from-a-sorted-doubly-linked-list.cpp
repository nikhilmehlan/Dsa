class Solution {
  public:
    Node *removeDuplicates(struct Node *head) {
        if (head == NULL || head->next == NULL) return head;
        Node* temp = head;

        while (temp && temp->next) {
            if (temp->data == temp->next->data) {
                Node* dup = temp->next;
                temp->next = dup->next;
                if (dup->next) dup->next->prev = temp;
                delete dup; // free memory if needed
            } else {
                temp = temp->next;
            }
        }

        return head;
    }
};
