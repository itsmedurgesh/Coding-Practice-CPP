#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> prevSmaller(vector<int> &A) {
    
    stack<int> s;
    vector<int> ans;
    
    for(int i = 0; i < A.size(); ++i){
        if(s.empty()) ans.push_back(-1);
        else{
            while(!s.empty() && A[s.top()] >= A[i]) s.pop();
            if(s.empty()) ans.push_back(-1);
            else ans.push_back(A[s.top()]);
        }
        s.push(i);
    }
    
    return ans;
}

int main(){
    vector<int> a = {1, 2, 3, 4, 5, 6, 7};
    vector<int> b = prevSmaller(a);
    for(int i : b) cout<<i<<" ";
}
