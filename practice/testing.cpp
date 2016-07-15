#include <iostream>
#include <climits>

using namespace std;

class Tableau{
private:
	int size;
	int A[10][10];
public:
	Tableau();
	void insert(int d);
	void print();
};

Tableau::Tableau(){
	size = 10;

	for(int i=0; i<size; ++i)
		for(int j=0; j<size; ++j)
			A[i][j] = INT_MAX;
}

void Tableau::insert(int d){
	A[size-1][size-1] = d;
	shiftup(size-1,size-1);
}


void Tableau::print(){
	for(int i=0; i<size; ++i){
		for(int j=0; j<size; ++j)
			cout<<A[i][j]<<" ";
		cout<<endl;
	}
}

int main(){
	Tableau t;
	t.insert(9);
	t.insert(16);
	t.insert(3);
	t.insert(2);
	t.insert(4);
	t.insert(8);
	t.insert(5);
	t.insert(14);
	t.insert(12);

	t.print();cout<<"done";
}
