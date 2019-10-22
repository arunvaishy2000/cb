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
    int n;
    cin>>n;
    for(int k=0;k<n;k++)
    {
         int d;
         cin>>d;
         arr[k]=d;
    }
    for(int j =n-2;j>=0;j--)
    {
        arr[j] = arr[j]+arr[j+1];
    }
    root =  arr2bst(arr,0,n-1);
    print(root);
    return 0;
}