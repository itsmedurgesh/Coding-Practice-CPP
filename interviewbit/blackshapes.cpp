#include <iostream>
#include <vector>
#include <stack>

using namespace std;
int black(vector<string> &A) {
    // Do not write main() function.
    //Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    stack<pair<int, int> > st;
    
    int count = 0;
    
    int M = A.size();
    int N = A[0].size();
    
    for(int i = 0; i < M; ++i){
        for(int j = 0; j < N; ++j){
            if(A[i][j] == 'X'){
                ++count;
                st.push(make_pair(i, j));
                A[i][j] = 'O';
                while(!st.empty()){
                    pair<int,int> p = st.top();
                    //check left child
                    if(p.second-1 >= 0 && A[p.first][p.second-1] == 'X'){
                        A[p.first][p.second-1] = 'O';
                        st.push(make_pair(p.first, p.second-1));
                    }
                    // check top child
                    else if(p.first-1 >= 0 && A[p.first-1][p.second] == 'X'){
                        A[p.first-1][p.second] = 'O';
                        st.push(make_pair(p.first-1, p.second));
                    }
                    // check right child
                    else if(p.second+1 < N && A[p.first][p.second+1] == 'X'){
                        A[p.first][p.second+1] = 'O';
                        st.push(make_pair(p.first, p.second+1));
                    }
                    //check bottom child
                    else if(p.first+1 < M && A[p.first+1][p.second] == 'X'){
                        A[p.first+1][p.second] = 'O';
                        st.push(make_pair(p.first+1, p.second));
                    }
                    else st.pop();
                }
            }
        }
    }
    
    return count;
}

int main(){
    vector<string> a = { "OOOXOOO", "OOXXOXO", "OXOOOXO" };
    cout<<black(a);
}
