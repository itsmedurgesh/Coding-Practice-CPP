#include <iostream>

using namespace std;
void merge(int a[], int mid, int size);

void mergesort(int a[], int size){
	if(size <= 1) return;

	int mid = size/2;
	mergesort(a, mid);
	mergesort(a + mid, size - mid);
	merge(a, mid, size);
}

void merge(int a[], int mid, int size){
	int l = 0;
	int r = mid;

	int *ret = new int[size];

	int i=0;

	while(l < mid && r < size){
		if(a[l] < a[r])
			ret[i++] = a[l++];
		else
			ret[i++] = a[r++];
	}

	while(l < mid)
		ret[i++] = a[l++];

	while(r < size)
		ret[i++] = a[r++];

	for(int j = 0; j < i; ++j)
		a[j] = ret[j];
}


int main(){
	int a[] = {23,45,56,12,45,1,3,4,6,34567,32};
	int size = sizeof(a)/sizeof(int);
	mergesort(a, size);
	for(int i=0; i<size; ++i)
		cout<<a[i]<<" ";
}