class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0) return head;

        // Step 1: Compute the length of the list
        int len = 1;
        ListNode* temp = head;
        while(temp->next) {
            len++;
            temp = temp->next;
        }

        // Step 2: Make it a circular linked list
        temp->next = head;

        // Step 3: Find the new tail: len - (k % len) steps from the beginning
        k = k % len;
        int stepsToNewTail = len - k;
        while(stepsToNewTail--) {
            temp = temp->next;
        }

        // Step 4: Set the new head and break the loop
        head = temp->next;
        temp->next = nullptr;

        return head;
    }
};
