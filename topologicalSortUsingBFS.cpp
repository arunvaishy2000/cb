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
   void topologicalSort()
   {
       map<T,bool> visited;
       queue<T> q;
       map<T,int> indegree;
       
       for(auto i:adjList)
       {
           T node = i.first;
           visited[node]= false;
           indegree[node]=0;
       }

       for(auto i : adjList)
       {
           T u = i.first;
           for(T v:adjList[u])
           {
               indegree[v]++;
           }
       }

       for(auto i:adjList)
       {
           T node = i.first;
           if(indegree[node]==0)
           {
               q.push(node);
           }
       }

       while (!q.empty())
       {
           T node = q.front();
           q.pop();
           cout<<node<<"-->";

           for(auto neigh:adjList[node])
           {
               indegree[neigh]--;
               if(indegree[neigh]==0)
               {
                   q.push(neigh);
               }
           }
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
    g.topologicalSort();
   

    return 0;
    
}