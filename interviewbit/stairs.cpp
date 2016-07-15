#include <iostream>
#include <cstring>
using namespace std;

int calculate(int n, int* ar){
    if(n == 0) return 1;
    if(n == 1) return 2;
    if(ar[n] != 0) return ar[n];
    int res =  calculate(n-1, ar) + calculate(n-2, ar);
    ar[n] = res;
    return res;
}


int climbStairs(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int *ar = new int[A];
    //ar = {0};
    memset(ar, 0, A*sizeof(int));
    return calculate(A-1, ar); //call this based on 0 index
}

int main(){
    cout<<climbStairs(6);
}
