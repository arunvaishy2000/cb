#include<iostream>
#include<stack>
#include<vector>
#include<math.h>
using namespace std;
#define MAX 100000000
int  prime(int n)
{
    int i,j,temp,count=0;

    for(i=2;i<=MAX;i++)
    {
        temp=0;
        for(j=2;j<=sqrt(i);j++)
        {
            if(i%j==0)
            {
                temp=1;
                break;
            }
        }
        if(temp==0)
        {
            count++;
        }
        if(count==n)
        {
            return i;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    int q;
    cin>>q;
    stack <int> s1;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        s1.push(a);
    }
    
    stack <int> s2,s3;
    for(int i=0;i<q;i++)
    {
        if(s1.empty())
        break;

        int cur = prime(i+1);
        while(!s1.empty())
        {
            int ele = s1.top();
            s1.pop();
            if(ele%cur == 0)
            {
                s2.push(ele);
            }
            else
            {
                s3.push(ele);
            }
        }
        while(!s2.empty())
        {
            cout<<s2.top()<<endl;
            s2.pop();
        }
        s1 =s3;
        while( !s3.empty())
        {
            s3.pop();
        }
    }
    while( !s1.empty())
    {
        cout<<s1.top()<<endl;
        s1.pop();
    }


	return 0;
}