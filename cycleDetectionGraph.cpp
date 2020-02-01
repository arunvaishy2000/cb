#include<bits/stdc++.h> 
#include<iostream>
#include<cstring>
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
   int isCycle(T src)
   {
       map<T,bool> visited;
       map<T,T> parent;
       queue<T> q;

       q.push(src);
       visited[src]=true;
       parent[src] = src;

       while(!q.empty())
       {
           T node = q.front();
           q.pop();
           for(auto neigh : adjList[node])
           {
               if(visited[neigh]==true && parent[node]!= neigh)
               {
                   return true;
               }
               else if(!visited[neigh])
               {
                   visited[neigh]=true;
                   parent[neigh] = node;
                   q.push(neigh);
               }
               
           }
       }
       return false;
   }
};

int main()
{
    Graph<int> g;
    g.addEdge(1,2);
    g.addEdge(1,4);
    //g.addEdge(4,3);
    g.addEdge(2,3);
    if(g.isCycle(1))
    {
        cout<<"Cyclic Graph"<<endl;
    }
    else
    {
        cout<<"Acyclic Graph"<<endl;
    }
    
   

    return 0;
    
}