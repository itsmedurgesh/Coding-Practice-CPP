#include <iostream>

using namespace std;

class First{
	public:
	int x;
	
		void operator+(First *o){
		x = x + o->x;
	}

};

/*
First First::operator+(First &o){
	this->name = this->name + o->name;
	return this;
}
*/

int main(){

	First *f = new First();
	First *l = new First();
	
	f->x = 8;
	l->x = 10;
	
//	f->operator+(l);
	f+l;
	
	cout<<f->x;
}
