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
    vector<pair<int, int>> ranges;
    int level = 0;
    if(l == 1) l = 0;
    while(l < r){
        while(l % getrange(level) == 0 && l + getrange(level) <= r) ++level;
        --level;
        int count = 0;
        long nextrange = getrange(level+1);
        long delta = getrange(level);
        while(l+delta <= r && (l == 0 || l % nextrange)){
            l += delta;
            ++count;
        }
        
        if(level == 0) ++count;
        ranges.push_back(make_pair(level, count));
        if(l%nextrange) break;
    }
    while(l < r){
        while(l + getrange(level) > r) --level;
        int count = 0;
        long delta = getrange(level);
        while(l+delta <= r){
            l += delta;
            ++count;
        }
        ranges.push_back(make_pair(level, count));
    }
    
    cout<<ranges.size()<<endl;
    for(auto a: ranges){
        cout<<a.first<<" "<<a.second<<endl;
    }
    return 0;
}
