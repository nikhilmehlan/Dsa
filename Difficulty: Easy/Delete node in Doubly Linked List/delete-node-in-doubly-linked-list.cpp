//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// A node of the doubly linked list
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

// Function to insert a node at the end
// of the Doubly Linked List
Node *push(Node *tail, int new_data) {
    // Allocate node
    Node *newNode = new Node(new_data);

    // Since we are adding at the end, next is NULL
    newNode->next = NULL;

    // Make newNode's previous pointer point to the current tail
    newNode->prev = tail;

    // If the tail is not null, link it to the new node
    if (tail != NULL)
        tail->next = newNode;

    // Return the new node as the new tail
    return newNode;
}

// Function to print nodes in a given doubly linked list
void printList(Node *head) {
    // If list is empty
    if (head == NULL)
        return;

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}


// } Driver Code Ends
/* Structure of Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
  public:
    // Function to delete a node at given position.
    Node* deleteNode(Node* head, int k) {
        // Your code here
    Node* temp = head;
    int cnt = 0;

    // Traverse the list to find the k-th node
    while (temp) {
        cnt++;
        if (cnt == k) break;
        temp = temp->next;
    }

    // If temp is null, k is out of bounds
    if (!temp) return head;

    Node* back = temp->prev;
    Node* front = temp->next;

    // Case 1: If it's the only node in the list
    if (back == nullptr && front == nullptr) {
        delete temp;
        return nullptr;
    }

    // Case 2: If the node to be deleted is the head node
    if (back == nullptr) {
        Node* back = head;
        head = head->next;
        head->prev = nullptr;
        back->next = nullptr;
        delete back; // Use delete instead of free
        return head;
    }

    // Case 3: If the node to be deleted is the tail node
    if (front == nullptr) {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        Node* previous = temp->prev;
        previous->next = nullptr;
        temp->prev = nullptr;
        delete temp; // Use delete instead of free
        return head;
    }

    // Case 4: If the node to be deleted is in the middle
    front->prev = back;
    back->next = front;
    temp->prev = nullptr;
    temp->next = nullptr;
    delete temp; // Use delete instead of free

    return head;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }

        Node *head = new Node(arr[0]);
        Node *tail = head;

        // Check if the array is empty
        for (size_t i = 1; i < arr.size(); ++i) {
            tail = push(tail, arr[i]);
        }

        int x;
        cin >> x;
        cin.ignore();

        Solution ob;
        head = ob.deleteNode(head, x);

        printList(head);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends