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
    void dfsHelper(T node,map <T,bool> &visited,list<T> &odering)
    {
        visited[node]= true;
        for(auto i:adjList[node])
        {
            if(!visited[i])
            {
                dfsHelper(i,visited,odering);
            }
        }
        odering.push_front(node);
    }
    void dfsTopologicalSort()
    {
        map<T,bool> visited;
        list<T> odering;

        for(auto i: adjList)
        {
            T node = i.first;
            if(!visited[node])
            {
                dfsHelper(node,visited,odering);
            }
        }

        for(T element: odering)
        {
            cout<<element<<"-->";
        }
    }
   
};

int main()
{
    Graph<string> g;
    g.addEdge("English","Programming Logic",false);
    g.addEdge("Maths","Programming Logic",false);
    g.addEdge("Programming Logic","HTML",false);
    g.addEdge("Programming Logic","Python",false);
    g.addEdge("Programming Logic","Java",false);
    g.addEdge("Programming Logic","JS",false);
    g.addEdge("Python","Web Dev",false);
    g.addEdge("HTML","CSS",false);
    g.addEdge("CSS","JS",false);
    g.addEdge("JS","Web Dev",false);
    g.addEdge("Java","Web Dev",false);
    g.addEdge("Python","Web Dev",false);
    g.dfsTopologicalSort();
   

    return 0;
    
}