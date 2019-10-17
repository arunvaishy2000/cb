#include <iostream>
#include<stack>
using namespace std;
void insertAtBottom(stack<int> &s, int x)
{
    if(s.empty()){
        s.push(x);
        return ;
     }
         int y= s.top();
         s.pop();
         insertAtBottom(s,x);
         s.push(y);

}
void reverseStack(stack<int> &s)
{
    if(s.empty())
        return ;

    int k = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s,k);
}
int main()
{
    int n;
    stack<int> s;
    cin>>n;
    for(int i=0;i<n;i++)
    {
       int t;
       cin>>t;
        s.push(t);
    }
    reverseStack(s);
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
}