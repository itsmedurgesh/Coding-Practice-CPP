#include <bits/stdc++.h>

using namespace std;

class Graph{
public:
    int V, E;
    vector<pair<int, pair<int, int>>> edges;

    Graph(int v, int e): V(v), E(e){}

    void addEdge(int a, int b, int w){
        edges.push_back(make_pair(w, make_pair(a, b)));
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

void kruskal(Graph &g){
    
    sort(g.edges.begin(), g.edges.end(), [](pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b){return a.first < b.first;});

    vector<pair<int, int>> parent;
    // parent.reserve(g.V);
    for(int i = 0; i < g.V; ++i) parent.push_back(make_pair(i, 0));
    int N = g.V;
    int c = 0;
    vector<pair<int, pair<int, int>>> res;
    while(N--){
       int x = find(parent, g.edges[c].second.first); 
       int y = find(parent, g.edges[c].second.second); 
       if(x != y){
           res.push_back(g.edges[c]);
           _union(parent, x, y);
       }
       ++c;
    }

    for(auto a: res){
        cout<<a.first<<": "<<a.second.first<<", "<<a.second.second<<endl;
    }
}

int main(){
    Graph g(4, 5);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);
    kruskal(g);
}
