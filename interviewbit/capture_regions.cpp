#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;


void solve(vector<string> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<pair<int, int> > toclear;
    stack<pair<int, int> > st;
    
    int M = A.size();
    int N = A[0].size();
    vector<vector<int>> visited(M, vector<int>(N, 0));
    
    for(int i = 1; i < M-1; ++i){
        for(int j = 1; j < N-1; ++j){
            if(A[i][j] == 'O' && visited[i][j] == 0){
                bool surround = true;
            
                visited[i][j] = 1;
                toclear.push_back(make_pair(i, j));
                // while(!st.empty()) st.pop();
                st.push(make_pair(i, j));
                
                while(!st.empty()){
                    pair<int, int> p = st.top();
                    //top child
                    if(p.first-1 >= 0 && A[p.first-1][p.second] == 'O' &&
                    visited[p.first-1][p.second] == 0){
                        if(p.first-1 == 0){ surround = false; }
                        
                        st.push(make_pair(p.first-1, p.second));
                        visited[p.first-1][p.second] = 1;
                        toclear.push_back(make_pair(p.first-1, p.second));
                    }
                    // right child
                    else if(p.second+1 < N && A[p.first][p.second+1] == 'O' &&
                    visited[p.first][p.second+1] == 0){
                        if(p.second+1 == N-1){ surround = false; }
                        
                        st.push(make_pair(p.first, p.second+1));
                        visited[p.first][p.second+1] = 1;
                        toclear.push_back(make_pair(p.first, p.second+1));
                    }
                    //bottom child
                    else if(p.first+1 < M && A[p.first+1][p.second] == 'O' &&
                    visited[p.first+1][p.second] == 0){
                        if(p.first+1 == M-1){ surround = false; }
                        
                        st.push(make_pair(p.first+1, p.second));
                        visited[p.first+1][p.second] = 1;
                        toclear.push_back(make_pair(p.first+1, p.second));
                    }
                    //left child
                    else if(p.second-1 >= 0 && A[p.first][p.second-1] == 'O' &&
                    visited[p.first][p.second-1] == 0){
                        if(p.second-1 == 0){ surround = false; }
                        
                        st.push(make_pair(p.first, p.second-1));
                        visited[p.first][p.second-1] = 1;
                        toclear.push_back(make_pair(p.first, p.second-1));
                    }
                    else st.pop();
                }
                
                if(!surround){
                    toclear.clear();
                }
                else{
                    for(auto p: toclear) A[p.first][p.second] = 'X';
                }
                
                while(!st.empty()) st.pop();
            }
        }
    }
    
}

int main(){
    vector<string> a = {"XOXXXXOOXX", "XOOOOXOOXX", "OXXOOXXXOO", "OXOXOOOXXO", "OXOOXXOOXX", "OXXXOXXOXO", "OOXXXXOXOO"};

    for(auto v: a){
        for(auto i: v) cout<<i<<" ";
        cout<<endl;
    }
    cout<<"modified.."<<endl;
    solve(a);

    for(auto v: a){
        for(auto i: v) cout<<i<<" ";
        cout<<endl;
    }
}
