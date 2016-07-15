#include <iostream>

using namespace std;

int main(){
    int B[8], C[6];
    
    int A[] = {2,5,3,0,2,3,0,3};
    
    int k = 5;

    for(int i=0; i<=k; ++i)
        C[i] = 0;
    
    for(int i=0; i<8; ++i)
        ++C[A[i]];

    for(int i=1; i<=k; ++i)
        C[i] += C[i-1];

    for(int i=7; i>-1; --i){
        B[C[A[i]]-1] = A[i];    // this -1 is because we are having 0 based array and not 1 based
        --C[A[i]];
    }
    for(int i : B)
        cout<<i<<" ";
}
        
