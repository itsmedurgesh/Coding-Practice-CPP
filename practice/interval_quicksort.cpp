// interval quicksort

#include <iostream>
#include <cstdlib>

using namespace std;

struct interval
{
	int left, right;
};


void swap(interval A[], int a, int b){ interval t = A[a]; A[a] = A[b]; A[b] = t;}

bool overlap(interval a, interval b){  return (a.left <= b.right && b.left <= a.right);}

bool before(interval a, interval b){ return a.right < b.left;}

bool after(interval a, interval b){ return a.left > b.right;}

pair<int, int> partition(interval A[], int s, int e){
	
	int pivot = s + rand()%(e-s);
	swap(A, pivot, e);

	int j = s-1;
	int k = e;

	for(int i = s; i<e; ++i)
		if(before(A[i], A[e]))
			swap(A, ++j, i);

	for(int i = e-1; i>= s; --i)
		if(after(A[i], A[e]))
			swap(A, --k, i);

	swap(A, e, k);	// swapping the last greater than pivot value found to the rightmost position

	return make_pair(++j, k);
}

void quicksort(interval A[], int s, int e){

	if(s >= e) return;

	pair<int, int> p = partition(A, s, e);

	quicksort(A, s, p.first -1);
	quicksort(A, p.second +1, e);
}

int main(){
	interval A[7];
	A[0] = (interval){10,11};
	A[1] = (interval){6,8};
	A[2] = (interval){5,8};
	A[3] = (interval){4,9};
	A[4] = (interval){2,3};
	A[5] = (interval){1,2};
	A[6] = (interval){2,55};

	quicksort(A, 0, 6);

	for(interval i: A)
		cout<<i.left<<" "<<i.right<<endl;

	// cout<<A[0].right<<endl;
}