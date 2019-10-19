#include <iostream>
using namespace std;

class node
{
public:
	int data;
	node*left;
	node*right;

	node(int d){
		data = d;
		left = right = NULL;
	}
};
node* insertInBST(node*root,int data)
{
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
void preorder(node* root)
{
    if(root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    return ;
}
void Print(struct node *root, int k1, int k2)
{
/* base case */
if ( NULL == root )
    return;

/* Since the desired o/p is sorted, recurse for left subtree first
    If root->data is greater than k1, then only we can get o/p datas
    in left subtree */
if ( k1 < root->data )
    Print(root->left, k1, k2);

/* if root's data lies in range, then prints root's data */
if ( k1 <= root->data && k2 >= root->data )
    printf("%d ", root->data );

/* If root->data is smaller than k2, then only we can get o/p datas
    in right subtree */
if ( k2 > root->data )
    Print(root->right, k1, k2);
    return;
}
int main()
{
    int t;
    cin>>t;
    for(int testcase =0 ;testcase<t;testcase++)
    {
        int n;
        cin>>n;
        node* root;
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            root = insertInBST(root,a);
        }
        int k1,k2;
        cin>>k1>>k2;
         cout<<"# Preorder : ";
         preorder(root);
         cout<<endl<<"# Nodes within range are : ";
         Print(root, k1,  k2);
         root =NULL:
    }
    return 0;
}