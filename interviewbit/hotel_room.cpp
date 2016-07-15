#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool hotel(vector<int> &arrive, vector<int> &depart, int K) {
    
    vector<pair<int, int>> intervals;
    intervals.reserve(arrive.size());
    for(int i = 0; i < arrive.size(); ++i){
        intervals.push_back(make_pair(arrive[i], depart[i]));
    }
    
    sort(intervals.begin(), intervals.end(), [](pair<int, int> &a, pair<int, int> &b){
        return a.first <= b.first;
    });
    
    vector<int> pending;
    
    for(int i = 0; i < intervals.size(); ++i){
        int d = intervals[i].first;
        for(auto it = pending.begin(); it != pending.end(); ++it) 
            if(*it == d){ pending.erase(it); break; }
        pending.push_back(intervals[i].second);
        if(pending.size() > K) return false;
    }
    
    return true;
    
}

int main(){
    vector<int> a = {30, 12, 15, 2, 21, 12, 1, 31, 7, 40, 29, 6, 48, 19, 23, 10, 26, 6, 20, 44, 44, 34, 44, 38};
    vector<int> d = {36, 54, 47, 19, 66, 33, 41, 69, 23, 80, 64, 28, 93, 23, 62, 15, 49, 19, 58, 64, 60, 60, 57, 82};
    cout<<hotel(a, d, 23);
}
