
bool check(unordered_map<char, int> &a, unordered_map<char, int> &b){
    for(auto it = b.begin(); it != b.end(); ++it){
        if(a.find(it->first) == a.end()) return false;
        else if(a[it->first] > b[it->first]) return false;
    }
    return true;
}


int Solution::exist(vector<string> &A, string B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    unordered_map<char, int> chars;
    unordered_map<char, int> current;
    for(char c: B) if(chars.find(c) == chars.end()) chars[c] = 1; else ++chars[c];
    
    int len = chars.size();
    
    int M = A.size();
    int N = A[0].size();
    // vector<vector<int>> v(M, vector<int>(N, 0));
    
    for(int i = 0; i < M; ++i){
        for(int j = 0; j < N; ++j){
            if(chars.find(A[i][j]) != chars.end()){
                //check right
                if(N-j >= len){
                    int k = j;
                    while(k < N && chars.find(A[i][k]) != chars.end()){
                        if(current.find(A[i][k]) == current.end())
                            current[A[i][k]] = 1;
                        else ++current[A[i][k]];
                        ++k;
                    }
                    if(check(current, chars)) return 1;
                    else current.clear();
                }
                //check down
                if(M-i >= len){
                    int k = i;
                    while(k < M && chars.find(A[k][j]) != chars.end()){
                        if(current.find(A[k][j]) == current.end())
                            current[A[k][j]] = 1;
                        else ++current[A[k][j]];
                        ++k;
                    }
                    if(check(current, chars)) return 1;
                    else current.clear();
                }
                // check left
                if(j+1 >= len){
                    int k = j;
                    while(k > -1 && chars.find(A[i][k]) != chars.end()){
                        if(current.find(A[i][k]) == current.end())
                            current[A[i][k]] = 1;
                        else ++current[A[i][k]];
                        --k;
                    }
                    if(check(current, chars)) return 1;
                    else current.clear();
                }
                // check up
                if(i+1 >= len){
                    int k = i;
                    while(k > -1 && chars.find(A[i][k]) != chars.end()){
                        if(current.find(A[k][j]) == current.end())
                            current[A[k][j]] = 1;
                        else ++current[A[k][j]];
                        --k;
                    }
                    if(check(current, chars)) return 1;
                    else current.clear();
                }
            }
            
        }
    }
    
    return 0;
}
