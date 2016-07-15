#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>

using namespace std;

double findkth(const vector<int> &A, int a, const vector<int> &B, int b, int k){
   if(a >= A.size()) return B[b + k-1];
   if(b >= B.size()) return A[a + k-1];

   if(k == 1) return min(A[a], B[b]);

   int akey = a + k/2-1 < A.size() ? A[a+k/2-1] : numeric_limits<int>::max();
   int bkey = b + k/2-1 < B.size() ? B[b+k/2-1] : numeric_limits<int>::max();
   if(akey < bkey) return findkth(A, a+k/2, B, b, k-k/2);
   else return findkth(A, a, B, b+k/2, k-k/2);

}
double findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    int total  = A.size()+B.size();
    if(total%2) return findkth(A, 0, B, 0, total/2+1);
    else return (findkth(A, 0, B, 0, total/2) + findkth(A, 0, B, 0, total/2+1))/2.0;
}
int main(){
    vector<int> A = {-50, -47, -36, -35, 0, 13, 14, 16};
    vector<int> B = {-31, 1, 9, 23, 30, 39};

    cout<<findMedianSortedArrays(A, B)<<endl;
}
