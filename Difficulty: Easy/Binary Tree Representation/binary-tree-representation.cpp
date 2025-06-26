// User function Template for C++

/*struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node *newNode(int data) {
  struct node *node = (struct node *)malloc(sizeof(struct node));

  node->data = data;

  node->left = NULL;
  node->right = NULL;
  return (node);
}*/

class Solution {
  public:

    void create_tree(node* root0, vector<int>& vec) {
        // Your code goes here
        root0->data=vec[0];
        queue<node*> q;
        q.push(root0);
        int i=1;
        int n=vec.size();
        while(i<n){
            node* curr=q.front();
            q.pop();
            
            if(i<n && curr->left==NULL){
                curr->left=newNode(vec[i]);
                q.push(curr->left);
                i++;
            }
            if(i<n && curr->right==NULL){
                curr->right=newNode(vec[i]);
                q.push(curr->right);
                i++;
            }
        }
    }
};