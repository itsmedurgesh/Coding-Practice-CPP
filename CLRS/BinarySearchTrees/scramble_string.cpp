#include <iostream>
#include <unordered_map>

using namespace std;

bool checkanagram(string a, string b){
unordered_map<char, int> h;

for(char c: a){
    if(h.find(c) == h.end()) h[c] = 1;
    else ++h[c];
}

for(char c: b){
    if(h.find(c) == h.end()) return false;
    else{
        if(h[c] == 0) return false;
        --h[c];
    }
}

h.clear();
return true;
}

int isScramble(const string A, const string B) {
// Do not write main() function.
// Do not read input, instead use the arguments to the function.
// Do not print the output, instead return values as specified
// Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

if(A.size() != B.size()) return 0;
if(A == B) return 1;
if(!checkanagram(A, B)) return 0;

for(int i = 1; i < A.size(); ++i){
    if(isScramble(A.substr(0, i), B.substr(0, i)) && isScramble(A.substr(i), B.substr(i)))
        return 1;
    if(isScramble(A.substr(0, A.size()-i), B.substr(i)) && isScramble(A.substr(A.size()-i), B.substr(0, i)))
        return 1;
}

return 0;
}

int test(){
    int t;
    return t = 2;
}
int main(){
    string a = "great";
    string b = "rgtea";

    cout<<isScramble(a, b)<<endl;
    cout<<test()<<endl;
}
