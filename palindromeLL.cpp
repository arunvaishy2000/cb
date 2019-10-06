#include<iostream>
using namespace std;

class node{

public:
	int data;
	node* next;

public:
	//Node Constructor
	node(int d){
		data = d;
		next = NULL;
	}
};
void insertAtHead(node*&head,int data){
	if(head==NULL){
		head = new node(data);
		return;
	}

	//otherwise!
	node* n = new node(data);
	n->next = head;
	head = n;
}
//Insert at tail
void insertAtTail(node*&head,int data){

	if(head==NULL){
		head = new node(data);
		return;
	}
	node*t = head;
	//bring t pointer to the last node
	while(t->next!=NULL){
		t = t->next;
	}
	//last node ->next attach new node
	t->next = new node(data);
	return;
}
int length(node*head){
	int l=0;
	while(head!=NULL){
		l++;
		head = head->next;
	}
	return l;
}

bool palindrome(node* head,int n)
{
    for(int j = n-1;j>0;j= j-2)
    {
    node* temp= head;
    for(int i=0;i<j;i++)
    {
        temp = temp->next;
    }
    if(head->data != temp->data)
    {
        return false;
    }
    head = head->next;
    }
    return true;
}

int main()
{
    int n;
    cin>>n;
    node* head = NULL;
    for(int k =0;k<n;k++){
            int d;
    cin>>d;
		insertAtTail(head,d);
	}
	if(palindrome(head,n))
    {
        cout<<"True";
    }
    else
    {
        cout<<"False";
    }

}