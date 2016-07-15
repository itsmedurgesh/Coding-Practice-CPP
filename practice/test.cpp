#include <iostream>

using namespace std;

void swap(int A[], int a, int b){
	int t = A[a];
	A[a] = A[b];
	A[b] = t;
}

pair<int, int> partition(int A[], int s, int e){
	int i = s-1;
	int k = e;

	
	for(int j = s; j<e; ++j)
		if(A[j] < A[e])
			swap(A, ++i, j);

	for(int j = e-1; j>= s; --j)
		if(A[j] > A[e])
			swap(A, --k, j);

	swap(A, e, --k);

	return make_pair(++i, k);
}

int main(){
	int A[] = {1,2,5,12,5,3,32,5,7,8,5,5};

	pair<int, int> p = partition(A, 0, sizeof(A)/sizeof(int)-1);

	cout<<p.first<<" "<<p.second<<endl;
}