#include <iostream>
using namespace std;


int isInterleave(string A, string B, string C) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int a = 0, b = 0, c = 0;
    
    while(c < C.size()){
        
        if(A[a] != C[c] && B[b] != C[c]) return 0;
        // longest match in s1
        int j = c;
        int i = a;
        
        while(i < A.size() && A[i] == C[j]){ ++i; ++j; }
        
        int k = b;
        j = c;
        while(k < B.size() && B[k] == C[j]) { ++k; ++j; }
        
        if(i-a >= k-b){ c += (i-a); a = i; }
        else{ c += (k-b); b = k; }
    }
    return 1;
    
}

int main(){
    string a = "kQMi2G2DP4lDVycU2kraW49wnJ5oNQ5szn7tZ7aMA8sM";
    string b = "J2qof422vinqzNsJIylQEZllxeSD";
    string c = "Jk2qof4Q2M2vi2Gi2nDqP4zNsJlDIyVylQEcUZ2llkrxaWe49SwDnJ5oNQ5szn7tZ7aMA8sM";

    cout<<isInterleave(a, b, c)<<endl;

    string s = "great";
    cout<<s.substr(2);

}
