#include <iostream>

using namespace std;

void swap(int A[], int i, int j){
	int t = A[i];
	A[i] = A[j];
	A[j] = t;
}

int partition(int A[], int s, int e){
	int i = s-1;
	int pivot = A[e];
	for(int j=s; j<e; ++j){
		if(A[j] <= pivot)
			swap(A, ++i, j);
	}

	swap(A, ++i, e);

	return i;
}

void insertionsort(int A[], int s, int e){
	for(int i=s+1; i<=e; ++i){
		int val = A[i];
		int j;
		for(j=i-1; j>=s && A[j] > val; --j){
			A[j+1] = A[j];
		}
		A[j+1] = val;
	}
}

void modified_quicksort(int A[], int s, int e, int thres){
	if((e-s) >= thres){
		int p = partition(A, s, e);
		modified_quicksort(A, s, p-1, thres);
		modified_quicksort(A, p+1, e, thres);
	}
	else if(s<e)
		insertionsort(A, s, e);
}

int main(){
	int A[] = {32,54,76,12,3,12,44,987,12,2,1};

	int thres = 2;
	
	modified_quicksort(A, 0, sizeof(A)/sizeof(int)-1, thres);
	// insertionsort(A, 0, sizeof(A)/sizeof(int)-1);

	for(int i:A)
		cout<<i<<" ";
}