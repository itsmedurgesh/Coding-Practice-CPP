#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct newcomp{
    int operator()(const auto &a, const auto &b){ return a.second < b.second; }} ;      

bool pair_compare(const auto &a, const auto &b){ return a.second < b.second; }

int main(){
    vector<int> a = {23, 645, 1212, 65, 23};
    vector<int> b = {4, 2, 5, 1, 3};
    vector<pair<int, int>> c;
    for(int i = 0; i < a.size(); ++i) c.push_back(make_pair(a[i], b[i]));

    newcomp  mycomp;
    // auto cc = [](const auto &a, const auto &b){ return a.second < b.second; };
    sort(c.begin(), c.end(), pair_compare);   
    for(auto i: c) cout<<i.first<<" ";  
}
