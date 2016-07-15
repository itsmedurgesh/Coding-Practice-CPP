#include <iostream>

using namespace std;

void reorder(int a[], int n, int i);
void heapify(int a[], int i);

void swap(int a[], int i, int j){
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
}

void make_heap(int a[], int size){
	for(int i=1; i<size; ++i){
		heapify(a, i);
	}
}

void heapify(int a[], int i){
	if(i == 0) return;
	int p = (i-1)/2;
	if(a[p] < a[i]){
		swap(a, p, i);
		heapify(a, p);
	}
}

void heapsort(int a[], int size){
	// first to make heap
	make_heap(a, size);

	for(int i = size-1; i > 0; --i){
		swap(a, 0, i);
		reorder(a, 0, i);
	}
}

void reorder(int a[], int i, int n){
	int j = 2*i + 1;
	int k = 2*i + 2;
	if(j >= n) return;

	int max = (a[j] > a[k]) ? j : k;
	if(k == n)	max = j;

	if(a[max] > a[i]){
		swap(a, i, max);
		reorder(a, max, n);
	}
}

int main(){
	int a[] = {43,12,87,1,433,87,2345,2356,44,77,89,2};
	int size = sizeof(a)/sizeof(int);
	heapsort(a, size);
	for(int i = 0; i < size; ++i)
		cout<<a[i]<<" ";
}