#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(){

    string A = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa ";
    vector<string> B;
    B.push_back("aaa");
    B.push_back("aaa");
    B.push_back("aaa");
    B.push_back("aaa");
    B.push_back("aaa");

    vector<int> res;
    if(A.length() == 0 || B.size() == 0) return 0;

    string h = "";
    for(string s: B){
        h += hash<string>()(s);
    }

    int len = B[0].length();

    for(int i = 0; i<A.length(); ++i){
        string s = A.substr(i, len*B.size());
        if(s.length() < len*B.size()) break;

        string h2  = "";
        for(int j = 0; j < B.size(); ++j){
            string ss = s.substr(j*len, len);
            h2 += hash<string>()(ss);
        }

        if(h == h2) res.push_back(i);
    }

    for(int i : res){
        cout<<i<<" ";
    }
}
