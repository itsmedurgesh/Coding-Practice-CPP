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

void quicksort(int A[], int s, int e){
	if(s<e){
		int p = partition(A, s, e);
		quicksort(A, s, p-1);
		quicksort(A, p+1, e);
	}
}

int main(){
	int A[] = {32,54,76,12,3,12,44,987,12,2,1};
	quicksort(A, 0, sizeof(A)/sizeof(int)-1);

	for(int i:A)
		cout<<i<<" ";
}

void something(){
    /** to do something here
     * also something here
     * this is just a multiline comment
     */
}
