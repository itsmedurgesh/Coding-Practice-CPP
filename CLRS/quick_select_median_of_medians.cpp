#include <iostream>
#include <array>
#include <algorithm>
#include <vector>

using namespace std;
/** this function gives a good point for partitioning the
 * array so that worst case running time for quick search is linear
 * this can also be applied to quick_sort
 */
int median_of_medians(vector<int> & v){

    if(v.size() <= 5){
        sort(v.begin(), v.end());
        return v[(v.size()-1)/2];
    }

    vector<int> w;

    int i;
    for(i=0; i<v.size()/5; ++i){
        sort(v.begin()+5*i, v.begin()+5*i+5);
        w.push_back(v[5*i+2]);
    }

        sort(v.begin()+5*i, v.end());
        w.push_back(v[5*i + (v.size() -5*i -1)/2]);
    
    return median_of_medians(w);
}


void swap(vector<int> & v, int i, int j){ int t = v[i]; v[i] = v[j]; v[j] = t; }

int quick_partition(vector<int> & v, int s, int e){
    
    vector<int> w(v.begin()+s, v.begin()+e);
    int p = median_of_medians(w);
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
    s.push_back(45);
    s.push_back(953);
    s.push_back(22);
    s.push_back(856);
    s.push_back(215);
    s.push_back(77);

    int k = quick_search(s, 0, s.size()-1, 7);
    cout<<k<<endl;
    s.clear();

}
