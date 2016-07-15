#include <iostream>

using namespace std;

// creating stream enables class
struct Dog
{	
	int _age;
	string _name;
};

ostream& operator<<(ostream& sm, const Dog& d){
	sm<<"My name is "<<d._name<<" and my age is "<<d._age<<endl;
	return sm;
}

istream& operator>>(istream& sm, Dog& d){
	sm >> d._age;
	sm >> d._name;
	return sm;
}

int main(){
	Dog d{2, "Bob"}; 	// Universal initialization from c++11
	cout<<d;

	cin>>d;
	cout<<d;
}