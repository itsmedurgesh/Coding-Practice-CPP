
#define MOD 1000000007

void transition(vector<int> &A, vector<int> &B, vector<int> &C, int D, int N, int &ans){
    if(N == 0){
        if(find(C.begin(), C.end(), D) != C.end()) if(ans < MOD) ++ans; else ans = 0;
        return;
    }

    transition(A, B, C, A[D], N-1, ans); // 0 transition
    transition(A, B, C, B[D], N-1, ans); // 1 transition
}

int Solution::automata(vector<int> &A, vector<int> &B, vector<int> &C, int D, int N) {
    
    if(N == 0) return find(C.begin(), C.end(), D) != C.end();
    
    int ans = 0;
    transition(A, B, C, A[D], N-1, ans); // 0 transition
    transition(A, B, C, B[D], N-1, ans); // 1 transition
    return ans;
}
