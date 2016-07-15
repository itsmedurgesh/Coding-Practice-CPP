#include <bits/stdc++.h>

using namespace std;

int minkey(vector<int> &key, vector<bool> &mstset, int V){
    int min = numeric_limits<int>::max(), midx;
    for(int i = 0; i < V; ++i){
        if(!mstset[i] && key[i] < min){
            min = key[i];
            midx = i;
        }
    }

    return midx;
}

void print(vector<int> &parent, int V, vector<vector<int>> &g){
    for(int i = 1; i < V; ++i)
        cout<<parent[i]<<" "<<i<<" "<<g[i][parent[i]]<<endl;
}

void prims(vector<vector<int>> &g, int src, int V){
    vector<bool> mstset(V, false);
    vector<int> key(V, numeric_limits<int>::max());
    vector<int> parent(V, -1);

    key[src]= 0;

    for(int i = 0; i < V-1; ++i){
        int u = minkey(key, mstset, V);
        mstset[u] = true;

        for(int j = 0; j < V; ++j){
            if(g[u][j] && !mstset[j] && g[u][j] < key[j])
                parent[j] = u, key[j] = g[u][j];
        }
    }

    print(parent, V, g);
}

int main(){
    
    vector<vector<int>> graph = {{0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0},
    };

    // Print the solution
    prims(graph, 0, 5);

    return 0;
}
