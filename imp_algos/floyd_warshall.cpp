#include <iostream>
#include <vector>
#include <limits>

using namespace std;
#define INF numeric_limits<int>::max()

void print(vector<vector<int>> &dist){
    for(auto a: dist){
        for(int b: a){
            cout<<b<<" ";
        }
        cout<<endl;
    }
}

void floyd_warshall(vector<vector<int>> &g){
    int N = g.size();
    vector<vector<int>> dist = g;

    for(int k = 0; k < N; ++k){
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                if(dist[i][k] != INF && dist[k][j] != INF &&
                        dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k]+dist[k][j];
            }
        }
    }
    print(dist);    
}

int main()
{
    /* Let us create the following weighted graph
            10
       (0)------->(3)
        |         /|\
      5 |          |
        |          | 1
       \|/         |
       (1)------->(2)
            3           */
    vector<vector<int>> graph = { {0,   5,  INF, 10},
                        {INF, 0,   3, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
                      };
 
    // Print the solution
    floyd_warshall(graph);
    return 0;
}
