#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
using namespace std;

int knapsack(auto &W, int i, int weight, int val, auto &V){
    if(i == W.size()) return val;
    
    int val1 = W[i] <= weight ? knapsack(W, i+1, weight-W[i], val+V[i], V) : numeric_limits<int>::min();
    int val2 = knapsack(W, i+1, weight, val, V);
    return max(val1, val2);
}

int knapsack_iterative(auto &W, int weight, auto &V){
    vector<vector<int>> d(W.size()+1, vector<int>(weight+1, 0));

    for(int i = 1; i <= W.size(); ++i){
        for(int j = 1; j <= weight; ++j){
            if(W[i-1] <= j)
                d[i][j] = max(V[i-1] + d[i-1][j-W[i-1]], d[i-1][j]);
            else
                d[i][j] = d[i-1][j];
        }
    }
    return d[W.size()][weight];
}

// int knapsack_multiple(auto &W, int weight, auto &V){
//     int i = 0;
//     for_each(V.begin(), V.end(), [&i](int &n){ n /= W[i++]; });
//     sort(V.begin(), V.end(), greater<int>());
//
//     i = 0;
//
//     while(weight > 0 && i < V.size()){
//         if(W[i] <= )
//     }
//
// }
int main(){
    vector<int> V = {60, 100, 120};
    vector<int> W = {10, 20, 30};
    int weight = 50;
    cout<<knapsack(W, 0, weight, 0, V)<<endl;
    cout<<knapsack_iterative(W, weight, V)<<endl;
    cout<<numeric_limits<float>::lowest()<<endl;
    int i = 0;
    for_each(V.begin(), V.end(), [&i, W](int &n){ n /= W[i++]; });
    sort(W.begin(), W.end(), [](int &a, int &b){ return a<b; });
    for_each(W.begin(), W.end(), [](int &n){ cout<<n<<" "; }); 
}
