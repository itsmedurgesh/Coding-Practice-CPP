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
    }
};

void topological_sort(Graph &g){
    vector<int> indegree(g.V, 0);

    for(int i = 0; i < g.V; ++i){
        for(auto it = g.adj[i].begin(); it!= g.adj[i].end(); ++it){
            ++indegree[(*it)];
        }
    }
    
    queue<int> q;

    for(int i = 0; i <g.V; ++i){
        if(!indegree[i]) q.push(i);
    }
    
    vector<int> sorted;
    int count = 0;

    while(!q.empty()){
        int f = q.front();
        q.pop();
        sorted.push_back(f);
        for(auto it = g.adj[f].begin(); it!= g.adj[f].end(); ++it)
            if(--indegree[*it] == 0) q.push(*it);
        ++count;
    }

    if(count != g.V) cout<<"\nnot possible";
    
    for(int i:sorted) cout<<i<<" ";
}

int main(){
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    topological_sort(g);
}
