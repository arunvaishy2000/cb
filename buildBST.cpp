#include<iostream>
#include<cstring>
using namespace std;
class node{
public:
	int data;
	node*left;
	node*right;

	node(int d){
		data = d;
		left = right = NULL;
	}
};
void print(node*root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	print(root->left);
	print(root->right);
}
void printIn(node*root){
	if(root==NULL){
		return;
	}
	printIn(root->left);
	cout<<root->data<<" ";
	printIn(root->right);
}
void printPost(node*root){
	if(root==NULL){
		return;
	}
	
	printPost(root->left);
	printPost(root->right);
	cout<<root->data<<" ";
}

node* insertInBST(node*root,int data){
	if(root==NULL){
		return new node(data);
	}
	if(data<=root->data){
		root->left = insertInBST(root->left,data);
	}
	else{
		root->right = insertInBST(root->right,data);
	}
	return root;
}
int height(node*root){
	if(root==NULL){
		return 0;
	}
	int h1 = height(root->left);
	int h2 = height(root->right);
	return max(h1,h2) +1;
}
void printAtLevelK(node*root,int k){
	if(root==NULL){
		return;
	}
	//otherwise
	if(k==0){
		cout<<root->data<<" ";
	}
	printAtLevelK(root->left,k-1);
	printAtLevelK(root->right,k-1);
	return;
}
void levelOrder1(node*root){

	int h = height(root);
	for(int k=0;k<h;k++){
		printAtLevelK(root,k);
		cout<<endl;
	}

}
node* arr2bst(int *arr,int s,int e){
	//base case
	if(s>e){
		return NULL;
	}

	int mid = (s+e)/2;
	node*root = new node(arr[mid]);
	root->left = arr2bst(arr,s,mid-1);
	root->right = arr2bst(arr,mid+1,e);
	return root;

}
int main()
{
    node* root;
    int arr[10000];
   int i;
  cin>>i;
    for(int j=0;j<i;j++){
        int n;
        cin>>n;
        for(int k=0;k<n;k++){
            int d;
            cin>>d;
            arr[k]=d;
        }
       root =  arr2bst(arr,0,n-1);
 print(root);
 }
    return 0;
}