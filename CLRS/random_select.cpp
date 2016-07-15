#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int> & v, int i, int j){ int t = v[i]; v[i] = v[j]; v[j] = t; }

int quick_partition(vector<int> & v, int s, int e){
    
    int p = v[e];
    int i = s-1;
    
    for(int j=s; j<e; ++j){
        if(v[j] <= p)
            swap(v, ++i, j);
    }

    swap(v, ++i, e);

    return i;
}


int quick_search(vector<int> & v, int s, int e, int k){
    if(s > e) return -1;

    if(s == e) return (k == 1) ? v[s] : -1;

    int p = quick_partition(v, s, e);
    int q = p - s + 1;

    if(q == k) return v[p];
    else{
        if(q < k) quick_search(v, p+1, e, k-q);
        else quick_search(v, s, p-1, k);
    }

}

int main(){
    vector<int> s;
    s.push_back(3);
    s.push_back(12);
    s.push_back(34);
    s.push_back(333);
    s.push_back(23);
    s.push_back(65);
    s.push_back(1);

    int k = quick_search(s, 0, s.size()-1, 3);
    cout<<k<<endl;
    s.clear();

}


