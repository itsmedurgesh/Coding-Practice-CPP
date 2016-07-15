#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

inline bool compare(string a, string b){ return a+b > b+a; }

int largestNumber(const vector<int> &A){
    vector<string> b;
    b.reserve(A.size());
    for(int i: A) b.push_back(to_string(i));

    sort(b.begin(), b.end(), compare);
    
    string res = "";
    for(string a: b) res += a;

    int i = 0;
    while(res[i] == '0' && i > res.size()-1) ++i;
    return stoi(res.substr(i));
}

int main(){
    vector<int> a = {3, 30, 34, 5, 9};
    cout<<largestNumber(a)<<endl;
}
