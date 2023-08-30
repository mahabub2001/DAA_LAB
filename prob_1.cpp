#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    vector<int>*adj;

    public:
    Graph(int V);
    void addEdge(int v1,int v2);
    void traverse();
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

void Graph::traverse()
{
    for(int i=0;i<V;i++)
    {
        cout<<i<<":";
        vector<int>::iterator it;
        for(it=adj[i].begin();it!=adj[i].end();it++)
        {
            cout<<*it<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int vertex,edge;
    cin>>vertex>>edge;

    Graph graph(vertex);
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
        graph.addEdge(arr[i][0],arr[i][1]);
    }

    graph.traverse();
}