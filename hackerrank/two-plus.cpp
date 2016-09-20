#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int calarea(vector<string> &grid, int i, int j, int k, int l, int r, int c){
    if((i == k && j == l) || grid[i][j] == 'B' || grid[k][l] == 'B')
        return -1;
    else{
        int ar1 = 1, ar2 = 1;
        int del1 = 1, del2 = 1;
        int flag = 1;
        vector<vector<bool>> visited(r, vector<bool>(c, 0));
        visited[i][j] = 1;
        visited[k][l] = 1;
        while(flag == 1){
            flag = 0;
            //# increment plus1
            if (i-del1 >= 0 && grid[i-del1][j] == 'G' && visited[i-del1][j] == 0 &&
                i+del1 < r && grid[i+del1][j] == 'G' && visited[i+del1][j] == 0 &&
                j-del1 >= 0 && grid[i][j-del1] == 'G' && visited[i][j-del1] == 0 &&
                j+del1 < c && grid[i][j+del1] == 'G' && visited[i][j+del1] == 0){
                ar1 += 4;
                visited[i-del1][j] = 1;
                visited[i+del1][j] = 1;
                visited[i][j-del1] = 1;
                visited[i][j+del1] = 1;
                del1 += 1;
                flag = 1;
            }
            //#increment plus2
            if (k-del2 >= 0 && grid[k-del2][l] == 'G' && visited[k-del2][l] == 0 &&
                k+del2 < r && grid[k+del2][l] == 'G' && visited[k+del2][l] == 0 &&
                l-del2 >= 0 && grid[k][l-del2] == 'G' && visited[k][l-del2] == 0 &&
                l+del2 < c && grid[k][l+del2] == 'G' && visited[k][l+del2] == 0){
                ar2 += 4;
                visited[k-del2][l] = 1;
                visited[k+del2][l] = 1;
                visited[k][l-del2] = 1;
                visited[k][l+del2] = 1;
                del2 += 1;
                flag = 1;
            }
        }
        visited[i][j] = 0;
        visited[k][l] = 0;
        return ar1 * ar2;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int r, c; cin>>r>>c;
    vector<string> grid; 

    string s;
    for(int i = 0; i < r; ++i){
        cin>>s;
        grid.push_back(s);
    }
    int maxarea = 0;
    for(int i = 0; i < r; ++i)
        for(int j = 0; j < c; ++j)
            for(int k = i; k < r; ++k)
                for(int l = 0; l < c; ++l)
                    maxarea = max(maxarea, calarea(grid, i, j, k, l, r, c));
    cout<<maxarea;

    return 0;
}
