#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    vector<int>*adj;

    public:
    Graph(int V);
    void addEdge(int v1,int v2);
    void shortest_path(int source);
};

Graph::Graph(int V)
{
    this->V=V;
    adj=new vector<int>[V];
}

void Graph::addEdge(int v1,int v2)
{
    adj[v1].push_back(v2);
}

void Graph::shortest_path(int source)
{

    vector<int>dist(V,INT_MAX);
    dist[source]=0;
    queue<int>q;

    q.push(source);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();

        for(auto neighbour:adj[x])
        {
            if(dist[neighbour]>dist[x]+1)
            {
                dist[neighbour]=dist[x]+1;
            }
            q.push(neighbour);
        }
    }

    for(int i=0;i<V;i++)
    {
        if(dist[i]==INT_MAX)
        {
            cout<<"Not Reachable"<<endl;
        }
        else
        {
            cout<<i<<":"<<dist[i]<<endl;
        }
    }
}

int main()
{
    int vertex,edge;
    cin>>vertex>>edge;

    Graph g(vertex);
    int arr[edge][2];
    for(int i=0;i<edge;i++)
    {
        for(int j=0;j<2;j++)
        {
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<edge;i++)
    {
        g.addEdge(arr[i][0],arr[i][1]);
    }

    g.shortest_path(0);
}



