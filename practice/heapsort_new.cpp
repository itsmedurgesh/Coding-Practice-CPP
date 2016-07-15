#include <iostream>
#include <cmath>

using namespace std;

void swap(int a[], int i, int j){
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
}

void max_heapify(int a[], int i, int size){
	int l = 2*i+1;
	int r = 2*i+2;

	int largest;
	if(l<size && a[l]>a[i])
		largest = l;
	else
		largest = i;

	if(r<size && a[r] > a[largest])
		largest = r;

	if(largest != i){
		swap(a, i, largest);
		max_heapify(a, largest, size);
	}


}

/** this function runs half the length because rest half are leaves and they are already max heaps hence we check and reorder only elements
*	before that point
*/

void make_heap(int a[], int size){
	for(int i = ceil(size/2); i>-1; --i)
		max_heapify(a, i, size);
}

void heap_sort(int a[], int size){
	for(int i = size-1; i>0; --i){
		swap(a, i, 0);
		max_heapify(a, 0, --size);
	}
}

int main(){
	int a[] = {19,2,3,4,5,6,7,8};
	make_heap(a, 8);
	heap_sort(a, 8);

	for(int i=0; i<8; ++i)
		cout<<a[i]<<" ";
}