#include <bits/stdc++.h>

using namespace std;

class Graph{
    public:
   int V, E;
    vector<vector<pair<int, int>>> adj;   

    Graph(int v, int e){
        V = v;
        E = e;
        adj.resize(V);
    }

    void addEdge(int a, int b, int w){
        adj[a].push_back(make_pair(b, w));
        adj[b].push_back(make_pair(a, w));
    }

};

void prims(Graph &g, int src){
    vector<pair<int, pair<int, int>>> res;

    set<pair<int, pair<int, int>>> s;
    int N = g.V-1;
    vector<bool> visited(g.E, false);
    visited[src] = true;
    
    //insert all neighbours of src

    for(auto it = g.adj[src].begin(); it != g.adj[src].end(); ++it){
        // adding to set (w, (s, d))
        s.insert(make_pair((*it).second, make_pair(src, (*it).first)));
    }

    while(N--){
        pair<int, pair<int, int>> p;
        do{
            p = *(s.begin());
            s.erase(s.begin());
        }while(visited[p.second.second]);   // because we can not visite same dst via different paths so we need to discard this edge

        int dst1 = p.second.second;
        int src1 = p.second.first;
        int w1 = p.first;

        res.push_back(make_pair(w1, make_pair(src1, dst1)));

        visited[dst1] = true;

        // add all unvisited neighbours of this dst vertex
        for(auto it = g.adj[dst1].begin(); it != g.adj[dst1].end(); ++it){
            if(!visited[(*it).first]){
                s.insert(make_pair((*it).second, make_pair(dst1, (*it).first)));
            }
        }
    }

    for(auto p : res){
        cout<<p.first<<": "<<p.second.first<<" -> "<<p.second.second<<endl;
    }
}

int main(){
    Graph g(9, 100);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    prims(g, 0);
}

