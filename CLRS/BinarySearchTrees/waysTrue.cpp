#include <iostream>
#include <vector>

using namespace std;

int ways(string A, bool val, int l, int r, vector<vector<vector<int>>> d){
    if(l > r) return 0;

    if(d[val][l][r] != -1) return d[val][l][r];

    if(l == r){
        if(A[l] == 'T'){
            if(val) d[val][l][r] = 1;
            else d[val][l][r] = 0;
        }
        if(A[l] == 'F'){
            if(val) d[val][l][r] = 0;
            else d[val][l][r] = 1;
        }
        return d[val][l][r];
    }

    int ans = 0;
    for(int i = l; i <= r; ++i){
        if(A[i] == '|'){
            if(val){
                ans += ways(A, true, l, i-1, d)*ways(A, true, i+1, r, d)
                    + ways(A, false, l, i-1, d)*ways(A, true, i+1, r, d)
                    + ways(A, true, l, i-1, d)*ways(A, false, i+1, r, d); 
                ans %= 1003;
            }
            else{
                ans += ways(A, false, l, i-1, d)*ways(A, false, i+1, r, d);
                ans %= 1003;
            }
        }
        else if(A[i] == '&'){
            if(val){
                ans += ways(A, true, l, i-1, d)*ways(A, true, i+1, r, d); 
                ans %= 1003;
            }
            else{
                ans += ways(A, false, l, i-1, d)*ways(A, false, i+1, r, d) 
                    + ways(A, false, l, i-1, d)*ways(A, true, i+1, r, d)
                    + ways(A, true, l, i-1, d)*ways(A, false, i+1, r, d);
                ans %= 1003;
            }
        }
        else if(A[i] == '^'){
            if(val){
                ans += ways(A, false, l, i-1, d)*ways(A, true, i+1, r, d)
                    + ways(A, true, l, i-1, d)*ways(A, false, i+1, r, d);
                ans %= 1003;
            }
            else{
                ans += ways(A, true , l, i-1, d)*ways(A, true, i+1, r, d)
                    + ways(A, false, l, i-1, d)*ways(A, false, i+1, r, d);
                ans %= 1003;
            }

        }
    }

    return d[val][l][r] = ans;
}


int main(){

    string a = "T^T^T^F|F&F^F|T^F^T";    
    vector<vector<vector<int>>> d(2, vector<vector<int>>(a.size(), vector<int>(a.size(), -1)));
    cout<<ways(a, true, 0, a.size()-1, d)<<endl;
}
