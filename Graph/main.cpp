#include <iostream>
#include <list>
#include <queue>
#include <stack>
/*  |V|=n
    0<=|E|<=n(n-1) if directed graph
    0<=|E|<=n(n-1)/2 if undirected graph
    assuming there is no self loop or multi edge
    Walk - A sequence of vertices where each adjacent pair is connected by an edge
        Closed Walk - Starts and ends at same vertex
            Simple Cycle - A closed walk in which no repetition other than start and end
    Path - A walk in which no vertices are repeated
    Trail - A walk in which no edges are repeated
*/
bool visitedDFS[100],visitedBFS[100];

using namespace std;

class graph{
    int V;
    list<int> *adj;

public:
    graph(int V);
    void addEdge(int v,int w);
    void BFS(int s);
    void DFS(int s);
};

graph::graph(int V){
    this->V=V;
    adj = new list<int> [V];
}

void graph::addEdge(int v,int w){
    adj[v].push_back(w);
}

void graph::BFS(int s){
    queue<int> q;

    visitedBFS[s]=true;
    q.push(s);

    list<int>::iterator i;

    while(!q.empty()){
        s=q.front();
        cout<<s<<" ";
        q.pop();

        for(i=adj[s].begin();i!=adj[s].end(); ++i){
            if(visitedBFS[*i]==false){
                visitedBFS[*i]=true;
                q.push(*i);
            }
        }
    }
}

void graph::DFS(int s){
    visitedDFS[s]=true;
    cout<<s<<" ";

    list<int>::iterator i;

    for(i=adj[s].begin();i!=adj[s].end(); ++i)
        if(visitedDFS[*i]==false)
            DFS(*i);
}

int main()
{
    graph g(6);
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(0,3);
    g.addEdge(1,0);
    g.addEdge(1,2);
    g.addEdge(1,4);
    g.addEdge(2,1);
    g.addEdge(2,4);
    g.addEdge(3,0);
    g.addEdge(3,4);
    g.addEdge(3,5);
    g.addEdge(4,3);
    g.addEdge(4,1);
    g.addEdge(4,5);
    g.addEdge(4,2);
    g.addEdge(5,3);
    g.addEdge(5,4);
    cout<<"BFS: ";
    g.BFS(0);
    cout<<"\nDFS: ";
    g.DFS(0);
    return 0;
}
