
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void helper(vector<int> &ans, int n, int sum, int a, int b, bool flag){
    if(n == 1){
        ans.push_back(sum);
        return;
    }   
    if(flag) helper(ans, n-1, sum+a, a, b, true);
    helper(ans, n-1, sum+b, a, b, false);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t; cin>>t;
    while(t--){
        int n, a, b; cin>>n>>a>>b;
        int _min = min(a, b)*(n-1);
        int _max = max(a, b)*(n-1);
        int diff = max(a, b) - min(a, b);
        for(int i = _min; i <= _max; i += diff) cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
