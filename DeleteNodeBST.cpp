#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* left;
    node* right;
    node(int data)
    {
        data = data;
        left = NULL;
        right = NULL;
    }
};
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
void print(node*root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	print(root->left);
	print(root->right);
    return;
}
node* deleteINBST(node *root,int val)
{
    if(val<root->data)
    {
        root->left = deleteINBST(root->left,val);
    }
    if(val>root->data)
    {
        root->right  = deleteINBST(root->right,val);
    }
    if(val == root->data)
    {
        if(root->left && root->right)
        { 
            delete root;
            return NULL;
        }
        else if(root->left==NULL and root->right!=NULL){
			node*temp = root->right;
			delete root;
			return temp;
		}
		else if(root->right==NULL and root->left!=NULL){
			node*temp = root->left;
			delete root;
			return temp;
		}
       else{
			//find the inorder successor
			node*temp = root->right;
			while(temp->left!=NULL){
				temp = temp->left;
			}
			root->data  = temp->data;
			root->right = deleteINBST(root->right,root->data);
			return root;
		}
    }
    return root;
}
int main()
{
    int t;
    cin>>t;
    for(int z=0;z<t;z++)
    {
        int n;
        cin>>n;
        int arr1[1000];
        int arr2[1000];
        node* root;
        for (int  i = 0; i < n; i++)
        {
            cin>>arr1[i];
        }
        int m;
        cin>>m;
        for (int j = 0; j < m; j++)
        {
            cin>>arr2[j];
        }
        for (int  i = 0; i < n; i++)
        {
            root = insertInBST(root,arr1[i]);
        }
        print(root);  
        for (int j = 0; j < m; j++)
        {

            root = deleteINBST(root,arr2[j]);
        }
        print(root);   
    }
}