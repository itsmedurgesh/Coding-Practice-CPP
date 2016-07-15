#include <iostream>

using namespace std;

struct  X
{
	X(int i){}
	X() {}

	void operator() (string s){
		cout<<"calling functor X with parameter "<<s<<endl;
	}

	operator string () const { return "X";}		// type conversion function
};


 int main(){
 	X foo;
 	foo("Hi");
 	X(10)("hola");		// we can also make parameterized functions

 }