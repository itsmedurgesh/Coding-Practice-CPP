#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

vector<int> flip(string A){

    vector<int> a;
    a.reserve(A.size());
    for(int i = 0; i < A.size(); ++i)
        if(A[i] == '1') a.push_back(-1);
        else a.push_back(1);

    int gs=-1, ge=-1, s=0, e=-1, sum = 0, tsum = -1;

    for(int i = 0; i<a.size(); ++i){
        sum += a[i];
        e = i;
        if(sum < 0){
            s = i+1;
            sum = 0;
            continue;
        }
        if(tsum < sum){
            tsum = sum;
            gs = s;
            ge = e;
        }
    }

    vector<int> ans;
    if(gs == -1) return ans;

    ans.push_back(gs+1);
    ans.push_back(ge+1);  
    return ans;

} 

bool check(vector<int> a, vector<int> b){ 
    if(a.size() != b.size()) return false;
    if(!a.size() && !b.size()) return true;
    return a[0] == b[0] && a[1]==b[1];}

    int main(){
        string v = "0101";
        assert(check(flip("01"), {1,1}));
        assert(check(flip("0101"), {1,1}));
        assert(check(flip("010"), {1,1}));
        assert(check(flip("01001"), {1,4}));
        assert(check(flip("011"), {1,1}));
        assert(check(flip("1101"), {3,3}));
        assert(check(flip("111"), {}));

    }
