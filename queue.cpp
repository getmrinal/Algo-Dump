#include <iostream>
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

Node *Push(Node*head){
	cout<<"enter the elements";
	int data;
	cin>>data;
	if(head==NULL){
		head = new Node(data);
		return Push(head);
	}else if(data == -1){
		return head;
	}else{
		Node*node = new Node(data);
		node->next = head;
		head = node;
		return Push(head);
	}
}
void printQueue(Node *head){
	Node* temp = head;
	while(temp!=NULL){
		cout<<temp->data;
		temp = temp->next;
	}
}

int main(){

		Node* head = NULL;
		head = Push(head);
		printQueue(head);

}