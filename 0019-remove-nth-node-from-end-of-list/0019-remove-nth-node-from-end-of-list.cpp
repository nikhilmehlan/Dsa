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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        // Move 'fast' n steps ahead
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        // If fast reached the end, remove the head
        if (fast == NULL) {
            ListNode* newHead = head->next;
            delete head;  // Use delete instead of free
            return newHead;
        }
        ListNode* slow = head;
        // Move both 'slow' and 'fast' together until fast reaches the last node
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        // Now slow->next is the node to be deleted
        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;  // Use delete instead of free
        return head;
    }
};
