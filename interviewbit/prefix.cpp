#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> prefix(vector<string> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    unordered_map<char, pair<string, int>> mapping;
    
    for(string s : A){
        if(mapping.find(s[0]) == mapping.end())
            mapping[s[0]] = make_pair(s, 1);
        else{
            auto tmp = mapping[s[0]];
            int i = 0;
            for(; i< tmp.first.length() && i < s.length(); ++i){
                if(s[i] != tmp.first[i]) break;
            }
            if(i == tmp.first.length()){
                mapping[s[i]] = make_pair(s, i+1);
            }
            else if(i+1 > tmp.second){
                mapping[s[i]] = make_pair(tmp.first, i+1);
            }
        }
    }
    
    vector<string> res;
    
    for(string s : A){
        auto ans = mapping[s[0]];
        res.push_back(s.substr(0, ans.second));
    }
    
    return res;

}


int main(){
    vector<string> v = {"zebra", "dog", "duck", "dot"} ;
    v = prefix(v);

    for(auto s : v){cout<<s<<endl;
    }

}
