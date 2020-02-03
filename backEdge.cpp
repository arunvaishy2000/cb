#include<bits/stdc++.h> 
#include<iostream>
#include<cstring>
#include<map>
#include<list>
#include<stack>
#include<queue>

using namespace std;

template<typename T>
class  Graph
{
    map< T, list<T> > adjList;

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
    bool isCycleHelper(T node,map<T,bool> &visited,map<T,bool> &inStack)
    {
        visited[node]= true;
        inStack[node]= true;
        for(auto neigh :adjList[node] )
        {
            if((!visited[neigh] && isCycleHelper(neigh,visited,inStack) )  ||   inStack[neigh]){
                 return true;
            }   
        }
        inStack[node] =false;
        return false;
    }
    bool isCycle()
    {
        map<T,bool> visited;
        map<T,bool> inStack;
        
        for(auto i : adjList)
        {
            T node = i.first;
            if(!visited[node])
            {
               bool cyclePresent = isCycleHelper(node,visited,inStack);
               if(cyclePresent)
               {
                   return true;
               }
            }
        }
        return false;
    }

};

int main()
{
    Graph<int> g;
    g.addEdge(0,2,false);
    g.addEdge(0,1,false);
    g.addEdge(2,3,false);
    g.addEdge(2,4,false);
   // g.addEdge(3,0,false);
    g.addEdge(4,5,false);
    g.addEdge(1,5,false);
    
    if(g.isCycle())
    {
        cout<<"Cyclic Graph"<<endl;
    }
    else
    {
        cout<<"Acyclic Graph"<<endl;
    }
    
   

    return 0;
    
}