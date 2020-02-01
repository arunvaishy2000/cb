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
    int  bsf(T src,T des)
    {
        queue<T> q;
        map<T,int> dist;
        map<T,T> parent;


        for(auto i : adjList)
        {
            dist[i.first] = INT_MAX;
        }


        q.push(src);
        dist[src] =0;
        parent[src] = src;

        while (!q.empty())
        {
            T node = q.front();
            cout<<node<<" ";
            q.pop();


            for(auto  neighbour : adjList[node])
            {
                if(dist[neighbour]== INT_MAX)
                {
                    q.push(neighbour);
                    dist[neighbour] = dist[node]+1;
                    parent[neighbour] = node;

                }
            }

        }
       for(auto i: adjList)
        {
            T node = i.first;
            cout<<"Distance of "<<node<<" From "<<src<<" is "<<dist[node]<<endl;
        }
        return dist[des];
        
    }
};

int main()
{
    Graph<int> g;
    int board[50] = {0};
    board[2]=13;
    board[5]=2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20]=-14;
    board[24]=-8;
    board[25]=-10;
    board[32]=-2;
    board[34]=-22;
    
    for(int u=0;u<=36;u++)
    {
        for(int dice=1;dice<=6;dice++)
        {
            int v = dice+u+board[u+dice];
            g.addEdge(u,v,false);
        }
    }

    cout<<"Shortest dis. is "<<g.bsf(0,36);

    return 0;
    
}