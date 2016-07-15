#include <iostream>
#include <limits>
#include <queue>
#include <vector>

using namespace std;

int mindistance(vector<int> &dist, vector<bool> &visited){
    int min = numeric_limits<int>::max(), minid = -1;
    int V = dist.size();
    for(int i= 0; i < V; ++i){
        if(!visited[i] && min > dist[i]){
        
            min = dist[i];
            minid = i;
        }
    }

    return minid;
}

void print(vector<int> &dist){
    for(int i = 0; i < dist.size(); ++i){
        cout<<i<<": "<<dist[i]<<endl;
    }
}

void dijkstra(vector<vector<int>> &graph, int src){
    int V = graph.size();
    vector<int> dist(V, numeric_limits<int>::max());
    vector<bool> visited(V, false);

    dist[src] = 0;
    int count = V;
    while(count--){
        int u = mindistance(dist, visited);
        visited[u] = true;

        for(int i = 0; i < V; ++i){
            if(!visited[i] && graph[u][i] && dist[u] != numeric_limits<int>::max()
                    && dist[u] + graph[u][i] < dist[i])
                dist[i] = dist[u] + graph[u][i];
        }

    }
    print(dist);
}

int main(){

    vector<vector<int>> graph = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 0, 10, 0, 2, 0, 0},
                      {0, 0, 0, 14, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
 
    dijkstra(graph, 0);
 
    return 0;

}
