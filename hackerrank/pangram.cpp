
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    vector<int> v(26, 0);
    string s;
    getline(cin, s);
    
    for(char c: s){
        if(c >= 'a' && c <= 'z') ++v[c-'a'];
        else if(c >= 'A' && c <= 'Z') ++v[c-'A'];
    }
    
    
    auto it = find_if(v.begin(), v.end(), [](const int a){return a == 0;});
    if(it == v.end()) cout<<"pangram";
    else cout<<"not pangram";
    
    return 0;
}
