//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
};



int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        MyQueue *sq = new MyQueue();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            sq->push(a);
        }else if(QueryType==2){
            cout<<sq->pop()<<" ";

        }
        }
        cout<<endl;
    
cout << "~" << "\n";
}
    }

// } Driver Code Ends


/* Structure of a node in Queue
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

And structure of MyQueue
struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
}; */

//Function to push an element into the queue.
void MyQueue:: push(int x)
{
        // Your Code
         QueueNode* temp = new QueueNode(x);

    // If the queue is empty, make the new node both front and rear.
    if (front == NULL) {
        front = temp;
        rear = temp;
    } else {
        // Otherwise, add the new node to the end of the queue and update rear.
        rear->next = temp;
        rear = temp;
    }
}

//Function to pop front element from the queue.
int MyQueue :: pop()
{
        // Your Code   
         if (front == NULL) return -1;

    // Get the data from the front node.
    int x = front->data;

    // Move the front pointer to the next node.
    QueueNode* temp = front;
    front = front->next;

    // If the queue becomes empty after popping, set rear to NULL.
    if (front == NULL) rear = NULL;

    // Delete the old front node.
    delete temp;

    return x;
}
