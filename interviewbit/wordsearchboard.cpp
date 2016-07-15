#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int exist(vector<string> &A, string B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int M = A.size();
    int N = A[0].size();
    vector<vector<int>> v(M, vector<int>(N, 0));
    stack<pair<int, int>> st;

    vector<pair<int, int>> toclear;

    for(int i = 0; i < M; ++i){
        for(int j = 0; j < N; ++j){
            if(A[i][j] == B[0]){

                int k = 1;
                st.push(make_pair(i, j));
                toclear.push_back(make_pair(i,j));

                while(!st.empty()){
                    pair<int, int> p = st.top();
                    //check right
                    if(p.second+1 < N && A[p.first][p.second+1] == B[k]
                            && v[p.first][p.second+1] == 0){
                        v[p.first][p.second+1] = 1;
                        st.push(make_pair(p.first, p.second+1));
                        toclear.push_back(make_pair(p.first, p.second+1));
                        k++;
                        if(k == B.size()) return 1;
                    }
                    //check bottom
                    else if(p.first+1 < M && A[p.first+1][p.second] == B[k]
                            && v[p.first+1][p.second] == 0){
                        v[p.first+1][p.second] = 1;
                        st.push(make_pair(p.first+1, p.second));
                        toclear.push_back(make_pair(p.first+1, p.second));
                        k++;
                        if(k == B.size()) return 1;
                    }
                    //check left
                    else if(p.second-1 > -1 && A[p.first][p.second-1] == B[k]
                            && v[p.first][p.second-1] == 0){
                        v[p.first][p.second-1] = 1;
                        st.push(make_pair(p.first, p.second-1));
                        toclear.push_back(make_pair(p.first, p.second-1));
                        k++;
                        if(k == B.size()) return 1;
                    }
                    //check up
                    else if(p.first-1 > -1 && A[p.first-1][p.second] == B[k]
                            && v[p.first-1][p.second] == 0){
                        v[p.first-1][p.second] = 1;
                        st.push(make_pair(p.first-1, p.second));
                        toclear.push_back(make_pair(p.first-1, p.second));
                        k++;
                        if(k == B.size()) return 1;
                    }
                    else{ st.pop(); k--; }
                }
                for(auto p: toclear){
                    v[p.first][p.second] = 0;
                }
                toclear.clear();

            }

        }
    }

    return 0;
}
int main(){
    vector<string> a = { "FEDCBECD", "FABBGACG", "CDEDGAEC", "BFFEGGBA", "FCEEAFDA", "AGFADEAC", "ADGDCBAA", "EAABDDFF" } ;
    for(string s: a){for(char c: s) cout<<c<<" "; cout<<endl;}
    cout<<exist(a, "BCDCB")<<endl;
}
