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

Node*insertNode(Node*head,int data[],int size){
	Node*temp =head;
	for(int i=0;i<size;i++){
		if(head==NULL){
			Node *head = new Node(data[i]);
			temp = head;
		}else{
			cout<<'@';
			Node *node = new Node(data[i]);
			temp->next = node;
			temp = temp->next;
		}
	}
	return head;
}
Node* printll(Node*head){
	Node*temp=head;
	while(temp!=NULL){
		cout<<temp->data<<"-->";
		temp = temp->next;
	}
}

Node *insertRecursively(Node*head,Node*temp){
	cout<<"enter no to insert";
	int data;
	cin>>data;
	if(head==NULL){
		head = new Node(data);
		temp = head;
		return insertRecursively(head,temp);

	}else if(data == -1){
		return head;

	}else{
		Node*node = new Node(data);
		temp->next = node;
		temp = temp->next;
		return insertRecursively(head,temp);
	}
}

Node*altReverse(Node*head){
	int count=1;
	Node*temp = head;
	Node*oddHead = NULL;
	Node*evenHead = NULL;
	Node*eHead = NULL;
	while(temp!=NULL){
		if(count%2!=0){
			if(oddHead==NULL){
				oddHead = new Node(temp->data);
				head = oddHead;
				
			}else{
				Node *node = new Node(temp->data);
				oddHead->next = node;
				oddHead = oddHead->next;
				
			}
			
		}else{
			if(evenHead==NULL){
				evenHead = new Node(temp->data);
				eHead = evenHead;
			}else{
				Node*node = new Node(temp->data);
				evenHead->next = node;
				evenHead = evenHead->next;
			}

		}
		temp = temp->next;
		count++;
	}
	oddHead->next = eHead;
	return head;
}

Node*altReverseEff(Node*head){

		Node *temp = head;



}

int main(){
		int data[]={1,2,3,4,5,6};
		int size = 6;
		Node *head =NULL;
		Node*temp = head;
		//head = insertNode(head,data,size);
		head = insertRecursively(head,temp);
		printll(head);
		cout<<'\n';
		head = altReverse(head);
		printll(head);
}