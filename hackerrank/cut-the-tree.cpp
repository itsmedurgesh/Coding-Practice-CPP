
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;
class Graph{
    public:
    int V;
    vector<int> vals;
    vector<vector<int>> adj;
    Graph(int v){
        V = v;
        vals.reserve(v);
        adj.reserve(v);
    }
    
    void addEdge(int a, int b){
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    
    int cumulatevals(int root, int parent){
        int val = vals[root];
        for(auto it = adj[root].begin(); it != adj[root].end(); ++it){
            if(*it != parent) val += cumulatevals(*it, root);
        }
        return vals[root] = val;
    }
};

int getmincut(Graph &g, int root, int total, vector<bool> &V){
    int diff = numeric_limits<int>::max();
    V[root] = true;
    for(auto it = g.adj[root].begin(); it != g.adj[root].end(); ++it){
        diff = min(diff, abs(total - 2*g.vals[*it]));
    }
    
    for(auto it = g.adj[root].begin(); it != g.adj[root].end(); ++it){
        if(!V[*it]) diff = min(diff, getmincut(g, *it, total, V));
    }
    

    return diff;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N; cin>>N;
    Graph g(N);
    int d;
    for(int i = 0; i < N; ++i){
        cin>>d;
        g.vals.push_back(d);
    }
    int a, b;
    for(int i = 0; i < N-1; ++i){
        cin>>a>>b;
        g.addEdge(a, b);
    }
    
    vector<bool> V(g.V, false);
    int total = g.cumulatevals(0, 0); //root is 0
    
    cout<<getmincut(g, 0, total, V);
    return 0;
}
