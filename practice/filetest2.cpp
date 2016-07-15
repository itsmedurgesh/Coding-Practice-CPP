#include <iostream>
#include <fstream>

using namespace std;

int main(){

	// writing the file
	ofstream fh("players.txt");
	
	cout<<"Enter players id, name, money\n";
	cout<<"press ctrl+D to end\n";

	int id;
	string name;
	float money;
	while(cin>>id>>name>>money)
		fh<<id<<" "<<name<<" "<<money<<endl;

	fh.close();

	// reading the file
	ifstream writer("players.txt");

	while(writer>>id>>name>>money)
		cout<<id<<", "<<name<<", "<<money<<endl;
}
