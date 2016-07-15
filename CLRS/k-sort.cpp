#include <iostream>
#include <algorithm>
using namespace std;

void k_merge(int a[], int k, int start, int mid, int end){
    
    int lid = start, rid = mid+k;

    int *b;
    b = new int[(end-start)/k + 1];
    
    int t = -1;
    while(lid <= mid && rid <= end){
        if(a[lid] < a[rid]){
            b[++t] = a[lid];
            lid+=k;
        }
        else{
            b[++t] = a[rid];
            rid += k;
        }
    }
    while(lid <= mid){
        b[++t] = a[lid];
        lid += k;
    }
    while(rid <= end){
        b[++t] = a[rid];
        rid += k;
    }
    t = 0;
    for(int p = start; p <= end; p+=k){
        a[p] = b[t];
        ++t;
    }
    
}


void k_mergesort(int a[], int k, int start, int end){

    if(start >= end) return;

    int mid = start + k*((end/k - start/k)/2);

    k_mergesort(a, k, start, mid);
    k_mergesort(a, k, mid+k, end);

    k_merge(a, k, start, mid, end);
}


void k_sort(int a[], int k, int colsize){

   for(int i=0; i<k; ++i)
       k_mergesort(a, k, i, i+(colsize-1)*k);

}


int main(){
    int A[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    random_shuffle(begin(A), end(A));

    for(int i:A)
        cout<<i<<" ";
    
    k_sort(A, 3, (sizeof(A)/sizeof(int))/3);
    
    cout<<endl;

    for(int i:A)
        cout<<i<<" ";
    

}
