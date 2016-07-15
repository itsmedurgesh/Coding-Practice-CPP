#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
int wordBreak(string A, vector<string> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    unordered_map<string, bool> dict;
    for(string s: B) dict[s] = true;
    
    int N = A.size();
    vector<vector<bool>> dp(N+1, vector<bool>(N+1, false));
    
    for(int i = 1; i <= N; ++i){
        if(dict.find(A.substr(0,i)) != dict.end()){
            dp[0][i] = true;
            continue;
        }
        for(int j = 1; j < i; ++j){
            if(dict.find(A.substr(j,i-j)) != dict.end()){
                dp[j][i] = true;
            }
            if(dp[0][j] && dp[j][i]){
                dp[0][i] = true;
                break;
            }
        }
    }
    
    
    return dp[0][N];
}

int main(){

    string a = "myinterviewtrainer";
    vector<string> b = {"interview", "my", "trainer"};

    cout<<wordBreak(a, b)<<endl;
}
