/* this is one crazy problem
 * solution in editorial is incomprehensible
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int numzeros(int level){
    if(level == 0) return 0;
    else return pow(2, level-1);
}

int zeros(string s){
    int c = 0;
    for(int i = s.size()-1; i>=0 && s[i] == '0'; --i) ++c;
    return c;
}

string addone(string s, int rpos){
    string t = s;
    if(rpos == t.size()) {
        t.insert(0, "1");
        return t;
    }
    
    int c = 1;
    for(int i = t.size()-1-rpos; i >= 0; --i){
        int x = t[i]-'0';
        int sum = x+1;
        c = sum/10;
        sum %= 10;
        t[i] = (char)(sum+'0');
        if(c == 0) break;
    }
    if(c) t.insert(0,"1");
    return t;    
}

string subone(string s){
    string t = s;
    int i = t.size()-1;
    while(i>=0 && t[i] == '0'){
        t[i] = '9';
        --i;
    }
    t[i] = (char)((((int)t[i]-'0')-1) + '0');
    return t;
}

bool isless(string a, string b){
    if(a.size() < b.size()) return true;
    if(a.size() > b.size()) return false;
    
    for(int i = 0; i < a.size(); ++i) {
        if(a[i] < b[i]) return true;
        if(a[i] > b[i]) return false;
    }

    if(a[a.size()-1] == b[b.size()-1]) return true;
    return false;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string l, r; cin>>l>>r;
    int level = 0;
    
    r = addone(r, 0);
    vector<pair<int, int>> ranges;
    while(l != "1" && zeros(subone(l)) >= numzeros(level+1)) ++level;
    
    int count = 0;
    while(true){
        if(zeros(subone(l)) >= numzeros(level+1) && isless(addone(l, numzeros(level+1)),r)){
            // cout<<level<<" "<<count<<endl;
            if(count) ranges.push_back(make_pair(level, count));
            ++level;
            count = 0;
        } 
        if(isless(addone(l, numzeros(level)),r)){
            l = addone(l, numzeros(level));
            ++count;    
        }
        else{
            
            // cout<<level<<" "<<count<<endl;
            if(count) ranges.push_back(make_pair(level, count));
            --level;
            count = 0;
        }        
        if(l == r) break;
    }
    // if(count) cout<<level<<" "<<count<<endl;
    if(count) ranges.push_back(make_pair(level, count));
    
    cout<<ranges.size()<<endl;
    for(auto a: ranges) cout<<a.first<<" "<<a.second<<endl;
    return 0;
}
