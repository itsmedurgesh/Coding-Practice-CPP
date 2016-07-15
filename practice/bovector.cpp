#include <iostream>

using namespace std;

template<typename T>
T square(T x){ return x*x;}

template<typename T>
class Bovector{
	T arr[1000];
	int size;

public:
	Bovector(): size(0){}

	void push(T x){ arr[size++] = x;}

	T get(int i) const { return arr[i]; }

	int getsize() const { return size;}

	void print() const { for(int i=0; i<size; i++) cout<<arr[i]<<" ";}

};

template<typename T>
Bovector<T> operator* (const Bovector<T> &v1, Bovector<T> &v2){
	Bovector<T> ret;
	for(int i=0; i<v1.getsize(); i++){
		ret.push(v1.get(i)*v2.get(i));
	}

	return ret;
}

int main(){

	cout<<square(3)<<endl;

	Bovector<int> bv;
	bv.push(12);
	bv.push(2);
	bv.push(3);
	bv.push(4);
	bv.push(5);
	// bv.print();

	bv = square(bv);
	bv.print();
}
