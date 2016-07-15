#include <iostream>
#include <vector>

using namespace std;

int helper(vector<int> &A, int m, int sum, vector<int> &dp){
    if(sum == 0 && m >= 0) return 1;
    if(sum < 0) return 0;
    if(sum > 0 && m == 0) return 0;
    
    if(dp[sum] != -1) return dp[sum];
    int res =  helper(A, m, sum - A[m-1], dp) + helper(A, m-1, sum, dp);
    dp[sum] = res % 1000007;
    return res % 1000007;
}

int coinchange2(vector<int> &A, int B) {
    vector<int> dp(B+1, -1);
    dp[0] = 1;

    return helper(A, A.size(), B, dp);

int main(){
    vector<int> v = {1,2,3};
    cout<<coinchange2(v, 4);
}
