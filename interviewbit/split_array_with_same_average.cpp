#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


bool possible(int id, int sum1, int length, auto &dp, vector<int> &res1, vector<int> &v){
    if(length == 0) return sum1 == 0;
    if(id >= length) return false;

    if(dp[id][sum1][length] == false) return false;

    if(sum1 >= v[id]){
        res1.push_back(v[id]);
        if(possible(id+1, sum1-v[id], length-1, dp, res1, v)) return true;
        res1.pop_back();
    }

    if(possible(id+1, sum1, length, dp, res1, v)) return true;

    return dp[id][sum1][length] = false;
}


vector<vector<int>> getsplits(vector<int>& v){
    vector<vector<int>> res(2, vector<int>());
    if(v.size()<=1) return res;

    int sum = 0;
    for(int i: v) sum += i;

    if(sum % 2) return res;
    
    int N = v.size();
    float avg = (float)sum/(float)N;

    sort(v.begin(), v.end());
    vector<vector<vector<bool>>> dp(N, vector<vector<bool>>(sum+1, vector<bool>(N, true)));

    // for returning
    vector<int> res1, res2;

    // iterate over size of s1 starting from size 1

    for(int i = 1; i < N; ++i){
        if((sum*i) % N) continue;
        int sum1 = sum*i/N;
        if(possible(0, sum1, i, dp, res1, v)){
            int p1 = 0, p2 = 0;
            while(p1 < v.size() && p2 < res1.size()){
                if(res1[p2] == v[p1]){
                    ++p1; ++p2;
                }
                else{ res2.push_back(v[p1]); ++p1; }
            }

            res.push_back(res1);
            res.push_back(res2);
            return res;
        }
    }

    return res; 

}

int main(){
    vector<int> vec = {1, 7, 15, 29, 11, 9};

    auto ans = getsplits(vec);
    for(int i : ans[0]) cout<<i<<" ";

    cout<<endl;
    for(int i : ans[1]) cout<<i<<" ";

}
