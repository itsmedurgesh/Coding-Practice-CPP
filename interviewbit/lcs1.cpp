#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getlcs(string &A, int s1, int e1, int s2, int e2){
    if(s1 > e1 || s2 < e2) return 0;
    
    if(A[s1] == A[s2]) return 1 + getlcs(A, s1+1, e1, s2-1, e2);
    else return max(getlcs(A, s1+1, e1, s2, e2), getlcs(A, s1, e1, s2-1, e2));
}

vector<int> maxLCS(string A) {
    int maxj = 1;
    int maxval = 0;
    
    for(int j = 0; j < A.size(); ++j){
        int l = getlcs(A, 0, j, A.size()-1, j+1);
        if(l > maxval){
            maxval = l;
            maxj = j;
        }
    }
    
    vector<int> ans;
    ans.push_back(maxj);
    ans.push_back(maxval);
    return ans;
}

int main(){
    vector<int> a = maxLCS("rarcoacwnmzpjrxycnqktkryutpqv");
    cout<<a[0]<<" "<<a[1];
}
