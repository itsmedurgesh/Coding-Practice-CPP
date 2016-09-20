#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long getrange(int level){
    long range;
        if(level == 0) range = 1;
        else
            range = (long)pow((long)10, (long)pow((long)2, (long)level-1));
    return range;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int l, r; cin>>l>>r;
    int level = 0;
    
    ++r;
    vector<pair<int, int>> ranges;
    while(l != 1 && (l-1)%getrange(level+1) == 0) ++level;
    
    int count = 0;
    while(l < r){
        if((l-1)%getrange(level+1) == 0 && l+getrange(level+1) <= r){
            // cout<<level<<" "<<count<<endl;
            if(count) ranges.push_back(make_pair(level, count));
            ++level;
            count = 0;
        } 
        if(l + getrange(level) <= r){
            l += getrange(level);
            ++count;    
        }
        else{
            
            // cout<<level<<" "<<count<<endl;
            if(count) ranges.push_back(make_pair(level, count));
            --level;
            count = 0;
        }        
    }
    // if(count) cout<<level<<" "<<count<<endl;
    if(count) ranges.push_back(make_pair(level, count));
    
    cout<<ranges.size()<<endl;
    for(auto a: ranges) cout<<a.first<<" "<<a.second<<endl;
    return 0;
}
