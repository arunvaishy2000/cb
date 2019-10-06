#include<iostream>
using namespace std;
void findZeros(int *arr,int  n,int  k)
{
    int wL=0,wR=0,bestL=0,bestwindow=0,zeroCount=0;
    while(wR<n)
    {
        if(zeroCount<=k)
        {
            if(arr[wR]==0)
            {
                zeroCount++;
            }
            wR++;
        }
        if(zeroCount>k)
        {
            if(arr[wL]==0)
            {
                zeroCount--;
            }
            wL++;
        }
        if( (wR-wL)>bestwindow and (zeroCount<=k))
        {
            bestwindow = wR-wL;
            bestL = wL;
        }
    }
        cout<<bestwindow<<endl;
    for(int i=0;i<bestL;i++) {
        cout<<arr[i]<<" ";
    }
    for(int i=bestL;i<bestL+bestwindow;i++) {
        if(arr[i]==0)
            arr[i]=1;
        cout<<arr[i]<<" ";
    }
    for(int i=bestL+bestwindow;i<n;i++) {
        cout<<arr[i]<<" ";
    }
    
}
int main() {
int n, k;
    cin>>n>>k;
    int *arr = new int[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    findZeros(arr, n, k);
    return 0;
}