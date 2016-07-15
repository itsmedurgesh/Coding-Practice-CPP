#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<vector<int>> A = {{1,0,1,1},{0,1,1,1},{0,1,0,1},{1,1,1,1}};
    int rows = A.size();
    int cols = A[0].size();

    vector<vector<int>> h(rows, vector<int>(cols, 0));
    vector<vector<int>> l(rows, vector<int>(cols, 0));
    vector<vector<int>> r(rows, vector<int>(cols, 0));

    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < cols; ++j){
            if(i == 0) h[i][j] = A[i][j];
            else if(A[i][j] == 0) h[i][j] = 0;
            else h[i][j] = h[i-1][j]+1;
        }
    }

    for(int i = 0; i < rows; ++i){
        int p = -1;
        for(int j = 0; j < cols; ++j){
            if(j == 0) l[i][j] = A[i][j];
            else if(A[i][j] == 0){ l[i][j] = j-p+1; p = j; }
            else l[i][j] = min(l[i-1,][j], j-p);

    
        }
    
    }
}
