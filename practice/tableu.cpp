#include <iostream>
#include <climits>

using namespace std;

class Tableau{
private:
	int size;
	int A[10][10];
	void shiftup(int m, int n);
	void shiftdown(int m, int n);
public:
	Tableau();
	void insert(int d);
	int min();
	int extract_min();
	pair<int, int> search(int k);
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

void Tableau::shiftup(int m, int n){
	if(m==0 && n==0) return;

	int p = m ,q = n;
	
	// finding the index of bigger element from above and left
	if(m-1 > -1){
		if(n-1 > -1){
			if(A[m-1][n] > A[m][n-1]){ p = m-1; q = n;}
			else{ p = m; q = n-1;}
		}
		else{ p = m-1; q = n;}
	}
	else{ p = m; q = n-1;}

	// if that element is bigger than current element we swap it
	if(A[p][q] > A[m][n]){
		int t = A[p][q];
		A[p][q] = A[m][n];
		A[m][n] = t;
		shiftup(p, q);
	}
}

int Tableau::extract_min(){
	int min = A[0][0];

	if(min == INT_MAX) cout<<"Tableau is empty"<<endl;

	A[0][0] = INT_MAX;
	shiftdown(0,0);

	return min;
}

void Tableau::shiftdown(int m, int n){
	if(m == size && n == size) return;

	int p = m, q = n;

	// finding index of minimum element fron bottom and right
	if(m+1 < size){
		if(n+1 < size){
			if(A[m+1][n] < A[m][n+1]){ p = m+1; q = n;}
			else{ p = m; q = n+1;}
		}
		else{ p = m+1; q = n;}
	}
	else{ p = m; q = n+1;}

	// if that element is smaller than current element then we swap
	if(A[p][q] < A[m][n]){
		int t = A[p][q];
		A[p][q] = A[m][n];
		A[m][n] = t;
		shiftdown(p, q);
	}
}

int Tableau::min(){
	return A[0][0];
}

pair<int, int> Tableau::search(int k){
	int p = size-1;
	int q = 0;

	while(true){
		if(k == A[p][q]){
			return make_pair(p, q);
		}
		else if(k < A[p][q]){
			--p;
		}
		else{
			++q;
		}

		if(p == -1 || q == size){
			cout <<"not found"<<endl;
			break;
		}
	}
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
	t.insert(344);
	t.insert(8);
	t.insert(5);
	t.insert(14);
	t.insert(12);
	t.insert(32);
	t.insert(45);
	t.insert(64);

	t.print();
	cout<<"min is: "<<t.min()<<endl;
	cout<<"extracted min is: "<<t.extract_min()<<endl;
	cout<<"extracted min is: "<<t.extract_min()<<endl;
	t.print();

	pair<int, int> p = t.search(700);

	cout<<"index for search: "<<p.first<<" "<<p.second<<endl;

}