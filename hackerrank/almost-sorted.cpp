
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n; cin>>n;
    vector<int> A(n);
    for(int i = 0; i < n; ++i) cin>>A[i];

    int dip1 = -1, dip2 = -1;
    for(int i = 0; i < n-1; ++i){
        if(A[i] > A[i+1]){
            if(dip1 == -1)
                dip1 = i;                
            dip2 = i+1;
        }
        else if(A[i] == A[i+1] && dip2 == i){
            dip2 = i+1;
        }
    }
    if(dip1 == -1) cout<<"yes"<<endl;
    else{
        int t= A[dip1];
        A[dip1] = A[dip2];
        A[dip2] = t;
        bool f =true;
        for(int i = 0; i < n-1; ++i) if(A[i] > A[i+1]){f = false; break;}
        if(f)
            cout<<"yes\nswap "<<dip1+1<<" "<<dip2+1<<endl;
        else{
            t= A[dip1];
            A[dip1] = A[dip2];
            A[dip2] = t;
            reverse(A.begin()+dip1, A.begin()+dip2+1);
            f =true;
            for(int i = 0; i < n-1; ++i) if(A[i] > A[i+1]){f= false; break;}
            if(f) cout<<"yes\nreverse "<<dip1+1<<" "<<dip2+1<<endl;
            else cout<<"no"<<endl;
        }
    }

    return 0;
}
