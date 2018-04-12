#include<iostream>
using namespace std;

class Node{
	public:
	int data;
	Node*next;
	Node(int data){
		this->data = data;
		this->next = NULL;
	}
};

Node * Push(Node*head=NULL){
	cout<<"enter element in stack";
	int data;
	cin>>data;
	if(data ==-1){
		return head;
	}else if(head == NULL){
		head = new Node(data);
		return Push(head);
	}else{
		Node *node = new Node(data);
		node->next = head;
		head = node;
		return Push(head);

	}
}
void printStack(Node*head){
	Node*temp=head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp = temp->next;
	}
}
Node *pop(Node*head){
	if(head==NULL){
		return head;
	}else{
		head = head->next;
		return head;
	}
}
int main(){

		Node *head= new Node(7);
		//Node*temp = head;
		head = Push(head);
		printStack(head);
		cout<<'\n';
		head = pop(head);
		printStack(head);

}