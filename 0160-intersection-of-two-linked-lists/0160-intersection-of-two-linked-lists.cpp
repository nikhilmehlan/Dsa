/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
   // Helper function to find the collision point
   ListNode* collision(ListNode *headA, ListNode *headB, int diff) {
        ListNode* t1 = headA;
        ListNode* t2 = headB;
        
        // Move the pointer of the longer list 'diff' steps ahead
        for(int i = 0; i < diff; i++) {
            t1 = t1->next;
        }

        // Traverse both lists and find the intersection point
        while (t1 != t2) {
            t1 = t1->next;
            t2 = t2->next;
        }
        
        return t1;  // Will return NULL if there's no intersection
    }

    // Main function to find the intersection node
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        int n1 = 0, n2 = 0;
        
        // Calculate the length of the first list
        while (temp1) {
            n1++;
            temp1 = temp1->next;
        }
        
        // Calculate the length of the second list
        while (temp2) {
            n2++;
            temp2 = temp2->next;
        }
        
        // If headB is longer, call the collision with swapped parameters
        if (n2 > n1) {
            return collision(headB, headA, n2 - n1);
        } else {
            return collision(headA, headB, n1 - n2);
        }
    }
};
