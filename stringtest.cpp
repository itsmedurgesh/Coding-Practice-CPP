#include <iostream>
#include <string>
using namespace std;

int main(){
	string name;
	//cin >> name;
	getline(cin, name);

	cout << name << endl;
	cout<<name.at(7)<<endl;
}