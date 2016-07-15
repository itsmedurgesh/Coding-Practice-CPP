#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
using namespace std;

int maxgap(vector<int> &A){
    int mx = *max_element(A.begin(), A.end());
    int mn = *min_element(A.begin(), A.end());

    vector<pair<int, int>> buckets(A.size(), make_pair(-1, -1));

    double interval = (double)(A.size()-1)/((double)mx-(double)mn);

    for(int i : A){
        int idx = (int)(((double)i - (double)mn)*interval);
        if(buckets[idx].first == -1){ 
            buckets[idx].first = i;
            buckets[idx].second = i;
        }
        else{
            buckets[idx].first = min(buckets[idx].first, i);
            buckets[idx].second = max(buckets[idx].second, i);
        }
    }

    int result= 0;
    int prev = buckets[0].second;
    for(int i = 1; i < buckets.size(); ++i){
        if(buckets[i].first != -1) {
            result = max(result, buckets[i].first - prev);
            prev = buckets[i].second;
        }
    }

    return result;
}

int main(){
    vector<int> a = {100, 100, 100, 100, 100};
    cout<<maxgap(a)<<endl;    
}
