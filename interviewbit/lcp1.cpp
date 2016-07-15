#include <iostream>
#include <vector>

using namespace std;

#define MOD 1000000007

string getlcp(string a, string b){
    string c = "";
    int i = 0;
    while(i < a.size() && i < b.size() && a[i] == b[i]){
        c += a[i];
        ++i;
    }
    return c;
}
int LCPrefix(vector<string> &A, int B) {
    
    long ans = A.size();
    ans %= MOD;
    
    for(int i = 0; i < A.size()-1; ++i){
        string first = A[i];
        string second = A[i+1];
        string lcp = getlcp(first, second);
        
        int lsize = lcp.size();
        if(lsize < B) continue;
        
        ++ans;
        ans %= MOD;
        
        for(int j = i+2; j < A.size(); ++j){
            second = A[j];
            while(lsize > 0 && lcp[lsize-1] != second[lsize-1]) --lsize;
            if(lsize < B) break;
            ++ans;
            ans %= MOD;
        }
    }
    
    return (int)ans;
}

int main(){
    vector<string> a = {"iotedxwlef", "iotedxwlef", "iotedxwlef", "iotedxwlef", "iotedxwlef", "iotedxwlef", "iotedxwlef", "iotedxwtef", "iotedxwlef", "iotedxwlef", "iotedxwlef", "iotedxwlef", "iotedxwlef", "iotedxwlef", "iotedxwlef", "iotedxwlef", "iotedxwlef", "iotedxwlef"};
    int b = 10;

    cout<<LCPrefix(a, b);
}
