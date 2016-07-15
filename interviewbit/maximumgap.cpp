#include <iostream>
#include <vector>

using namespace std;
int maximumGap(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<pair<int,int>> B;
    B.reserve(A.size());
    for(int i = 0; i < A.size(); ++i) B.push_back(make_pair(A[i], i));
    
    sort(B.begin(), B.end(), [](const pair<int, int> &a, const pair<int, int> &b){
        return a.first < b.first;
    });
    
    vector<int> ind(B.size(), -1);
    
    int maxid = INT_MIN;
    for(int i = B.size()-1; i >= 0; --i){
        maxid = max(maxid, B[i].second);
        ind[i] = maxid;
    }
    
    int maxval = 0;
    for(int i = 0; i < B.size(); ++i){
        maxval = max(maxval, ind[i] - B[i].second);
    }
    
    return maxval;
}

int main(){
    

}
