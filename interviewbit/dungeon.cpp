#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int M = dungeon.size();
        int N = dungeon[0].size();
        // hp[i][j] represents the min hp needed at position (i, j)
        // Add dummy row and column at bottom and right side
        vector<vector<int> > hp(M + 1, vector<int>(N + 1, INT_MAX));
        hp[M][N - 1] = 1;
        hp[M - 1][N] = 1;
        for (int i = M - 1; i >= 0; i--) {
            for (int j = N - 1; j >= 0; j--) {
                int need = min(hp[i + 1][j], hp[i][j + 1]) - dungeon[i][j];
                hp[i][j] = need <= 0 ? 1 : need;
            }
        }
        return hp[0][0]; 
}
int main(){
    vector<vector<int>> v = {{-3, 5, -7, -100},{-20, -10, -5, 35},{-30, -5, -2, 10},{-40, -40, 20, -20}};
    cout<<calculateMinimumHP(v)<<endl;
}