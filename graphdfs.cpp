#include<bits/stdc++.h> 
#include<iostream>
#include<map>
#include<list>
#include<queue>

using namespace std;

template<typename T>
class  Graph{
    map< T, list<T>> adjList;

public:
    Graph()
    {
        
    }
    void addEdge(T u,T v,bool bidir = true)
    {
        adjList[u].push_back(v);
        if(bidir)
        {
            adjList[v].push_back(u);
        }
    }
    void printAdj(){
        for(auto i: adjList)
        {
            cout<<i.first<<"->";
            for(auto vertex : i.second)
            {
                cout<<vertex<<"->";
            }
            cout<<endl;
        }
    }
    void dfsHelper(T node,map<T,bool> &visited)
    {
        visited[node]=true;
        cout<<node<<" ";
        for(T neigh : adjList[node])
        {
            if(!visited[neigh])
            {
                dfsHelper(neigh,visited);
            }
        }
    }

    void dfs(T src)
    {
        map<T,bool> visited;
        int component =1;
        dfsHelper(src,visited);
        cout<<endl;

        for(auto i:adjList)
        {
            T n = i.first;
            if(!visited[n])
            {
                dfsHelper(n,visited);
                component++;
                cout<<endl;
            }
        }

        cout<<"The graph had "<<component<<" connected component"<<endl;
        return;
    }
};

int main()
{
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(0,4);
    g.addEdge(2,4);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(3,5);
    g.addEdge(9,10);
    g.dfs(0);
   

    return 0;
    
}