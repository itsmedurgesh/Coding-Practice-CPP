#include <bits/stdc++.h>

using namespace std;

class Graph{
public:
    int V;
    vector<list<int>> adj;
    Graph(int v){
        V = v;
        adj.resize(V);
    }

    void addEdge(int a, int b){
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
};

void bridgeUtil(Graph &g, int u, vector<bool> &visited, vector<int> &disc, vector<int> &low, vector<int> &parent){
    static int time = 0;

    visited[u] = true;

    disc[u] = low[u] = ++time;

    for(auto it = g.adj[u].begin(); it!= g.adj[u].end(); ++it){
        int v = *it;
        if(!visited[v]){
            parent[v] = u;
            bridgeUtil(g, v, visited, disc, low, parent);
            low[u] = min(low[u], low[v]);
            if(low[v] > disc[u]) cout<<u<<" "<<v<<endl;
        }
        else if(v != parent[u])
            low[u] = min(low[u], disc[v]);
    }
}

void bridge(Graph &g){
    vector<int> parent(g.V, -1);
    vector<int> disc(g.V);
    vector<bool> visited(g.V, false);
    vector<int> low(g.V);
    for(int i = 0; i < g.V; ++i){
        if(!visited[i])
            bridgeUtil(g, i, visited, disc, low, parent);
    }
}

int main()
{
    // Create graphs given in above diagrams
    cout << "\nBridges in first graph \n";
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    bridge(g1);
 
    cout << "\nBridges in second graph \n";
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    bridge(g2);
 
    cout << "\nBridges in third graph \n";
    Graph g3(7);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 0);
    g3.addEdge(1, 3);
    g3.addEdge(1, 4);
    g3.addEdge(1, 6);
    g3.addEdge(3, 5);
    g3.addEdge(4, 5);
    bridge(g3);
 
    return 0;
}
