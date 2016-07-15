#include <iostream>
#include <vector>
#include <map>

using namespace std;
void fillhash(map<int, vector<int>> &hash){
    vector<int> a = {32, 12,54, 12};
    // a.push_back(43);
    hash[2] = a;
}

int main(){
    map<int, vector<int>> hash;
    {
        vector<int> a = {1,2,3,5,5};
        hash[1] = a;
    }
    fillhash(hash);
    vector<int> b = hash[2];

    cout<<sizeof(vector<double>);// it always take 24 bytes
    // for(int i : b)  cout<<i<<" ";
}
