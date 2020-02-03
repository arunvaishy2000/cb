#include<bits/stdc++.h> 
#include<iostream>
#include<cstring>
#include<unordered_map>
#include<list>
#define ll long long

using namespace std;

template<typename T>
class  Graph
{
    map< T, list< pair<T,ll> > >adjList;

public:
    Graph(ll v)
    {
        for(ll i=1;i<=v;i++)
        {
            adjList[i];
        }
    }
    void addEdge(T u,T v,ll dis ,bool bidir = true)
    {
        adjList[u].push_back(make_pair(v,dis));
        if(bidir)
        {
            adjList[v].push_back(make_pair(u,dis ));
        }
    }
     void printAdj(){
        for(auto i: adjList)
        {
            cout<<i.first<<"->";
            for(auto vertex : i.second)
            {
                cout<<"( "<<vertex.first<<","<<vertex.second<<" )"<<"-> ";
            }
            cout<<endl;
        }
    }
    void dijsktraSSSP(T src)
    {
        map<T,ll> dist;
        for(auto j: adjList)
        {
            dist[j.first]=INT_MAX;
        }
        
        set< pair<int,T> > s;
        
        dist[src] =0;
        s.insert(make_pair(0,src));
        
        while(!s.empty()){
            auto p = *(s.begin());
            T node = p.second;
            int nodeDist = p.first;
            s.erase(s.begin());
            
            for(auto child : adjList[node])
            {
                if(nodeDist + child.second < dist[child.first])
                {
                    T des= child.first;
                    auto f = s.find(make_pair(dist[des],des)); 
                    
                    if(f!= s.end())
                    {
                        s.erase(f);
                    }
                    
                    dist[des] = nodeDist + child.second;
                    s.insert(make_pair(dist[des],des));
                }
            }
        }
        for(auto g:dist){
            if(g.second == INT_MAX)
            {
                g.second = -1;
            }
        }
        
        for(auto d:dist){
            cout<<d.second<<" ";
        }
        
    }
 

};

int main()
{
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        Graph<int> g(n);
        while(m--){
            ll x,y,r;
            cin>>x>>y>>r;
            g.addEdge(x,y,r);
        }
        ll src;
        cin>>src;
        g.dijsktraSSSP(src);
        cout<<endl;
    }
    
    return 0;
    
}