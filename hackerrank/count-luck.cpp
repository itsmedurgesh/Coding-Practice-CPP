// updated code on hackerrank
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

pair<bool, int> getpath(vector<string> &F, vector<vector<bool>> &V, int row, int col, int n, int m, int waves){
    if(F[row][col] == '*') return make_pair(true, waves);
    V[row][col] = true;
    
    int count = 0;
    if(row-1 >= 0 && F[row-1][col] == '.') ++count;
    if(row+1 < n && F[row+1][col] == '.') ++count;    
    if(col-1 >= 0 && F[row][col-1] == '.') ++count;
    if(col+1 < m && F[row][col+1] == '.') ++count;
    if(count > 1) ++waves;
    
    //go up
    if(row-1 >= 0 && (F[row-1][col] == '.' || F[row-1][col] == '*') && !V[row-1][col]){
        auto a = getpath(F, V, row-1, col, n, m, waves);
        if(a.first) return a;
    }        
    //go down
    if(row+1 < n && (F[row+1][col] == '.' || F[row+1][col] == '*') && !V[row+1][col]){
        auto a = getpath(F, V, row+1, col, n, m, waves);
        if(a.first) return a;
    }
    //go left
    if(col-1 >= 0 && (F[row][col-1] == '.' || F[row][col-1] == '*') && !V[row][col-1]){
        auto a = getpath(F, V, row, col-1, n, m, waves);
        if(a.first) return a;
    }
    //go right
    if(col+1 < m && (F[row][col+1] == '.' || F[row][col+1] == '*') && !V[row][col+1]){
        auto a = getpath(F, V, row, col+1, n, m, waves);
        if(a.first) return a;
    }
    
    return make_pair(false, -1);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<string> F(n);
        for(int i = 0; i < n; ++i) cin>>F[i];

        vector<vector<bool>> V(n, vector<bool>(m, false));

        int k; cin>>k;
        pair<bool, int> a;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(F[i][j] == 'M')
                    a = getpath(F, V, i, j, n, m, 0);
            }
        }

        if(a.second == k) cout<<"Impressed"<<endl;
        else cout<<"Oops!"<<endl;
    }
    
    return 0;
}
