#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

void swap(vector<int> & A, int i, int j){
    if(i == j) return;
	int t = A[i];
	A[i] = A[j];
	A[j] = t;
}


int partition(vector<int> & red, vector<int> & blue, int start, int end){
    
    if(start == end) return start;
    if(start > end) return -1;


    int p = red[end];
    int i = start-1;

    for(int j = start; j<end; ++j){
        if(red[j] <= p)
            swap(red, ++i, j);

    }

    swap(red, ++i, end);

    for(int j = start; j<=end; ++j){
        if(blue[j] == p) swap(blue, j, end);
    }

    i = start-1;

    for(int j = start; j<end; ++j){
        if(blue[j] <= p)
            swap(blue, ++i, j);

    }

    swap(blue, ++i, end);

    return i;


}

void quicksort(vector<int> & red, vector<int> & blue, int start, int end){
    
    if(start >= end) return;

    int p = partition(red, blue, start, end);

    quicksort(red, blue, start, p-1);
    quicksort(red, blue, p+1, end);

}

int main(){

    vector<int> red, blue;
    for(int i=1; i<=10; ++i){ 
        red.push_back(i);
        blue.push_back(i);
    }

    srand(time(0));
    
    random_shuffle(red.begin(), red.end());
    random_shuffle(blue.begin(), blue.end());

    quicksort(red, blue, 0, red.size()-1);

    for(int i: blue)
        cout<<i<<" ";

    cout<<endl;
    for(int i:red)
        cout<<i<<" ";
}
