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

int find(vector<pair<int, int>> &parent, int i){
    if(parent[i].first != i) 
        parent[i].first = find(parent, parent[i].first); 
    else return parent[i].first;
}

void _union(vector<pair<int, int>> &parent, int x, int y){
    int xp = find(parent, x);
    int yp = find(parent, y);
    if(parent[xp].second < parent[yp].second)
        parent[xp].first = yp;
    else if(parent[yp].second < parent[xp].second)
        parent[yp].first = xp;
    else{
        parent[xp].first = yp;
        parent[yp].second++;
    }
}

bool isCycle(Graph &g){
    vector<pair<int, int>> parent;
    for(int i = 0; i < g.V; ++i){
        parent.push_back(make_pair(i, 0));
    }
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
