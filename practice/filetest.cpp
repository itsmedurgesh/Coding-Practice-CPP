#include <iostream>
#include <fstream>

using namespace std;

int main(){

	ofstream fh;
	fh.open("tuna.txt");

	fh<<"Bucky loves tune and i don't know why\n";
	fh.close();

	ofstream nfh("newtuna.txt");

	if(nfh.is_open())
		cout<<" the file is opened\n";
	nfh<<"this is also an example to use file\n";
	nfh.close();

}
