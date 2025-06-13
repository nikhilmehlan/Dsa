/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    Node* merge(Node* l1,Node* l2){
        Node* dummyNode=new Node(-1);
        Node* res=dummyNode;
        while(l1 && l2){
            if(l1->data<=l2->data){
                res->bottom=l1;
                res=l1;
                l1=l1->bottom;
            }
            else{
                res->bottom=l2;
                res=l2;
                l2=l2->bottom;
            }
            res->next=NULL;
        }
        if(l1){
            res->bottom=l1;
        }
        if(l2){
            res->bottom=l2;
        }
        if(dummyNode->bottom){
            dummyNode->bottom->next=NULL;
        }
        return dummyNode->bottom;
    }
    Node *flatten(Node *root) {
        // Your code here
      if(root==NULL || root->next==NULL) return root;
      Node* mergedHead=flatten(root->next);
      return merge(root,mergedHead);
    }
};