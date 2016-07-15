#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int possible(vector<int> &A, long long minpages, int maxele, int K){
    if(minpages < maxele) return 0;
    long long sum = 0;
    int count = 1;
    for(int i = 0; i < A.size();){
        if(sum + (long long)A[i] > minpages){
            sum = 0;
            count++;
        }
        else{
            sum += (long long)A[i];
            ++i;
        }
    }
    
    if(count <= K) return 1;
    return 0;
}


int books(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    
    if(B > A.size()) return -1;
    
    long long start = 0, end = 0;
    for(int i : A) end += i;
    
    long long ans = numeric_limits<int>::max();
    
    int maxele = *max_element(A.begin(), A.end());
    
    while(start <= end){
        long long mid = (start+end)/2;
        
        int p = possible(A, mid, maxele, B);
        if(p == 0){
            start = mid+1;
        }
        else{
            ans = min(ans, mid);
            end = mid-1;
        }
    }
    
    return (int)ans;
}

int main(){
    vector<int> a = {97, 26, 12, 67, 10, 33, 79, 49, 79, 21, 67, 72, 93, 36, 85, 45, 28, 91, 94, 57, 1, 53, 8, 44, 68, 90, 24};
    int b = 26;
    cout<<books(a, b)<<endl;
}
