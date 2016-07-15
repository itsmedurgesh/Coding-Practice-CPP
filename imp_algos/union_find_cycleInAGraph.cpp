#include <bits/stdc++.h>

using namespace std;

class Graph{
public:
    int V, E;
    vector<pair<int, int>> edges;
    Graph(int v, int e): V(v), E(e) {}
    void addEdge(int s, int d){
        edges.push_back(make_pair(s, d));
    }
};

int find(vector<int> &parent, int i){
    return (parent[i] == -1) ? i : find(parent, parent[i]); 
}

void _union(vector<int> &parent, int x, int y){
    int xp = find(parent, x);
    int yp = find(parent, y);
    parent[xp] = yp;
}

bool isCycle(Graph &g){
    vector<int> parent(g.V, -1);
    for(int i = 0; i < g.E; ++i){
        int x = find(parent, g.edges[i].first);
        int y = find(parent, g.edges[i].second);
        if(x == y) return true;
        _union(parent, x, y);
    }

    return false;
}

int main(){
    Graph g(3, 3);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(0, 2);
    cout<<isCycle(g)<<endl;
}
