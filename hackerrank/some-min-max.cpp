/* this code is wrong
 * TODO: solution needed
 */

/* problem statement
 * given an array of integers a1, a2 .. an
 * there are n! permutations
 * we have to find the minimum value of maximum values we get by taking XORs of two consecutive numbers
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void permute(vector<int> &A, int l, int r, int &fxor, int tmp){
    if(l == r){
        if(tmp < fxor) fxor = tmp;
        return;
    }
    
    for(int i = l+1; i <= r; ++i){
        tmp = max(tmp, A[i-1]^A[i]);
        swap(A[i], A[l]);
        permute(A, l+1, r, fxor, tmp);
        swap(A[i], A[l]);
    }
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    cin>>n;
    vector<int> A(n);
    int d;
    for(int i = 0; i < n; ++i){
        cin>>d;
        A[i] = d;
    }
    int fxor = 0x7fffffff, tmp = 0;
    permute(A, 0, n-1, fxor, tmp);
    cout<<fxor<<endl;
    
    return 0;
}
