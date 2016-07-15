#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    vector<int> a = { 1, 3, 5, 7, 2 ,76, 23, 54, 432, 6, 9};
    int K = 4;
    vector<int> b(K, 0);

    for(int i = 0; i < K; ++i) b[i] = a[i];

    srand(time(0));
    for(int i = K; i < a.size(); ++i){
        int t = rand()%(i+1);
        if(t < K) b[t] = a[i];
    }

    for(int i: b) cout<<i<<" ";
    cout<<endl;
}
