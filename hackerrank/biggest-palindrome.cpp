
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, k; cin>>n>>k;
    string s; cin>>s;
    unordered_set<int> mismatch;
    char biggest = '9';    
    for(int i = 0; i < n/2; ++i){
        if(s[i] != s[n-i-1]){
            mismatch.insert(i);
            char t = max(s[i], s[n-i-1]);
            s[i] = t;
            s[n-i-1] = t;
            --k;
        }            
    }
    
    if(k < 0) cout<<-1;
    else if(k == 0) cout<<s;
    else{
        for(int i = 0; i < n/2; ++i){
            if(s[i] != '9'){
                if(mismatch.find(i) != mismatch.end()){
                    s[i] = s[n-i-1] = biggest;
                    --k; 
                }
                else{
                    if(k > 1){
                        s[i] = s[n-i-1] = biggest;
                        k -= 2;
                    }
                }
                if(k <= 0) break;   
            }            
        }
        
        if(n&1 && k > 0) s[(n-1)/2] = '9';
        
        cout<<s;
    }
    
    return 0;
}
