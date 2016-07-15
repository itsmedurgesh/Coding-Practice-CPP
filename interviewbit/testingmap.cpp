#include <iostream>
#include <map>
#include <vector>

using namespace std;

int getMode(vector<int> &A){
    map<int, int> hash;
    for(int i: A){
        if(hash.find(i) == hash.end()) hash[i] = 1;
        else hash[i]++;
    }
    auto it = hash.end();
    --it;
    return it->second;
}

int main(){
    vector<int> a = {1,2,2,2,2,4,33,3,3};
    cout<<getMode(a);
}
