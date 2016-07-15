#include <iostream>
#include <vector>   

using namespace std;

int fun1(string s, string t){
    int m = s.size()+1;
    int n = t.size()+1;

    vector<vector<int>> d(m, vector<int>(n, 0));

    //empty T i.e first colum will be 1
    for(int i = 0; i < m; ++i) d[i][0] = 1;

    for(int i = 1; i < m; ++i){
        for(int j = 1; j < n; ++j){
            if(s[i] != t[j]) d[i][j] = d[i-1][j];
            else d[i][j] = d[i-1][j] + d[i-1][j-1];
        }
    }

    return d[m-1][n-1];
}

int fun2(string S, string T){
    int m = T.length();
    int n = S.length();

    if (m > n) return 0;    // impossible for subsequence

    vector<vector<int>> path(m + 1, vector<int>(n + 1, 0));

    for (int k = 0; k <= n; k++) path[0][k] = 1;    // initialization
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= m; i++) {
            path[i][j] = path[i][j - 1] + (T[i - 1] == S[j - 1] ? path[i - 1][j - 1] : 0);
        }
    }
    return path[m][n];
}

int main(){
    string s = "rabbbbitiitiiit";
    string t = "rabbit";
    cout<<fun1(s, t)<<endl;
    cout<<fun2(s, t)<<endl;
}
