#include <iostream>

using namespace std;

class Friend{
public:
	Friend(int n): var(n){ }
private:
	int var;

friend void Friendfriend(Friend &f);
};

void Friendfriend(Friend &f){
	cout<<f.var<<endl;
	f.var = 100;
	cout<<f.var<<endl;
}

int main(){

	Friend f(5);
	Friendfriend(f);
}