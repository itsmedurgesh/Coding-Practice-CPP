// #include <iostream>
// #include <list>
// #include <set>
// #include <limits>
// #include <vector>
#include <bits/stdc++.h>

using namespace std;
#define INF numeric_limits<int>::max()

class Graph{
public:
    int V;
    list<pair<int, int>> *adj;

    Graph(int v){
        V = v;
        adj = new list<pair<int, int>>[V];
    }

    void addEdge(int a, int b, int w){
        adj[a].push_back(make_pair(b, w));
        adj[b].push_back(make_pair(a, w));
    }
    
    void dijkstra(int src){
        set<pair<int, int>> s;
        vector<int> dist(V, INF);
        dist[src] = 0;
        s.insert(make_pair(0, src));

        while(!s.empty()){
            auto p = *(s.begin());
            s.erase(s.begin());
            int u = p.second;

            for(auto it = adj[u].begin(); it != adj[u].end(); ++it){
                int v = (*it).first;
                int weight = (*it).second;

                if(dist[u] + weight < dist[v]){
                    if(dist[v]!=INF) s.erase(s.find(make_pair(dist[v], v)));
                    dist[v] = dist[u] + weight;
                    s.insert(make_pair(dist[v],v));
                }
            }
        }

        for(int i = 0; i < V; ++i){
            cout<<i<<": "<<dist[i]<<endl;
        }
    }

};

int main()
{
    // create the graph given in above fugure
    int V = 9;
    Graph g(V);
 
    //  making above shown graph
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
 
    g.dijkstra(0);
 
    return 0;
}
