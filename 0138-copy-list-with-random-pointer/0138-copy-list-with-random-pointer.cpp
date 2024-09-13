/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* clone(Node* head){
	Node* temp=head;
	while(temp){
		Node* cNode=new Node(temp->val);
		cNode->next=temp->next;
		temp->next=cNode;
		temp=temp->next->next;
	}
	return head;
}
Node* giveRandom(Node* head){
	Node* temp=head;
	while(temp){
		Node* cNode=temp->next;
		if(temp->random){
			cNode->random=temp->random->next;
		}
		else{
			cNode->random=nullptr;
		}
		temp=temp->next->next;
	}
		return head;
}
Node* giveNext(Node* head){
	Node* dNode=new Node(-1);
	Node* res=dNode;
	Node* temp=head;
	while(temp){
		res->next=temp->next;
		temp->next=temp->next->next;
		res=res->next;
		temp=temp->next;
	}
	return dNode->next;
}
    Node* copyRandomList(Node* head) {
        clone(head);
	giveRandom(head);
	return giveNext(head);
    }
};