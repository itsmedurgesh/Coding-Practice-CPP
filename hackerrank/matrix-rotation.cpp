
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

pair<int,int> next(int i, int j, int mini, int minj, int maxi, int maxj){
    if(i == mini && j < maxj) return make_pair(i, j+1);
    if(i < maxi && j == maxj) return make_pair(i+1, j);
    if(i == maxi && j > minj) return make_pair(i, j-1);
    if(i > mini && j == minj) return make_pair(i-1, j);
    return make_pair(-1,-1);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int m, n, r; cin>>m>>n>>r;
    vector<vector<int>> A(m, vector<int>(n));
    for(int i = 0; i < m; ++i) 
        for(int j = 0; j < n; ++j) 
            cin>>A[i][j];
    
    int mini = 0, minj = 0, maxi = m-1, maxj = n-1;
    
    while(mini < maxi && minj < maxj){
        int rotations = r%((maxi-mini+1 + maxj-minj+1)*2);
        while(rotations--){
            int startval = A[mini][minj];
            int i = mini, j = minj;
            auto nx = next(i, j, mini, minj, maxi, maxj);
            
            while(nx.first != mini || nx.second != minj){
                A[i][j] = A[nx.first][nx.second];
                i = nx.first;
                j = nx.second;
                nx = next(i, j, mini, minj, maxi, maxj);
            }
            A[i][j] = startval;
        }   
        ++mini; ++minj; --maxi; --maxj;
    }
    
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            cout<<A[i][j]<<" ";
        }
        cout<<"\n";
    }
        
    return 0;
}
