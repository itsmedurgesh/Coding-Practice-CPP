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

void sort_helper(Graph &g, int v, stack<int> &st, vector<int> &visited){
    visited[v] = true;

    for(auto it = g.adj[v].begin(); it != g.adj[v].end(); ++it){
        if(!visited[(*it)]) sort_helper(g, (*it), st, visited);
    }

    st.push(v);
}

void topological_sort(Graph &g){
    stack<int> st;
    vector<int> visited(g.V, false);

    for(int i = 0; i < g.V; ++i){
        if(!visited[i]) sort_helper(g, i, st, visited);
    }

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
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
