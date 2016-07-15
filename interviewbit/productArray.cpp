#include <iostream>
#include <vector>

using namespace std;

vector<int> prod(vector<int> &a){
    vector<int> c(a.size(), 1);
    int temp = 1;

    for(int i = 0; i < a.size(); ++i){
        c[i] = temp;
        temp *= a[i];
    }

    temp = 1;
    for(int i = a.size()-1; i > -1; --i){
        c[i] *= temp;
        temp *= a[i];
    }

    return c;
}

int main(){
    vector<int> a = {2, 3, 5, 1, 7};
    vector<int> c = prod(a);
    for(int i: c) cout<<i<<" ";
}
