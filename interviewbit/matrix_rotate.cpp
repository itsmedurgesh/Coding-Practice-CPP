#include <iostream>
#include <vector>
using namespace std;

// this function does not work for non-square matrices..
void rotate(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int N = A.size();
    for(int i = 0; i < N/2; ++i){
        for(int j = i; j < N-i-1; ++j){
            int t = A[i][j];    // saving top left
            A[i][j] = A[N-1-j][i];  // copying bottom left to top right
            A[N-1-j][i] = A[N-1-i][N-1-j];  //copying bottom right to bottom left
            A[N-1-i][N-1-j] = A[j][N-1-i];  //copying top right to bottom right
            A[j][N-1-i] = t;    // copying the original top left to top right
        }
    }
}

int main(){
    vector<vector<int>> a= {{1,2},{3,4}};
    rotate(a);
    for(auto b: a){
        for(auto c:b) cout<<c<<" ";
        cout<<endl;
    }
}
