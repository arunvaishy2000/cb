#include<bits/stdc++.h> 

using namespace std;

int n=4;
int dp[16][4];
int dis[10][10]= {
    {0,20,42,25},
    {20,0,30,34},
    {42,30,0,10},
    {25,34,10,0}
};
int visitedAll = (1<<n)-1;

int tsp(int mask,int pos)
{
    if(mask == visitedAll)
    {
        return dis[pos][0];
    }
    if(dp[mask][pos]!= -1)
    {
        return dp[mask][pos];
    }

    int ans = INT_MAX;
    for(int city = 0;city<n;city++)
    {
        if((mask &(1<<city))==0)
        {
            int newAns = dis[pos][city] + tsp((mask|(1<<city)),city);
            ans = min(ans,newAns);
        }

    }
    dp[mask][pos]= ans;
    return ans;
}

int main()
{
    for(int i=0;i<(1<<n);i++)
    {
        for(int j=0;j<n;j++)
        {
            dp[i][j]=-1;
        }
    }
    cout<<"Min weight hamiltonian path cost is : "<<tsp(1,0)<<endl;
    return 0;

}