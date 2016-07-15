#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	// we can apply all the algos of containers 
	string a = "this is a new line";
	int num = count(a.begin(), a.end(), 'i');	// counting the occurences in container
	cout<< num<< endl;

	num = count_if(a.begin(), a.end(), [](char c){return c >= 'a' && c <= 'e';});
	cout<< num<< endl;

	a = "hola bitchesss whatcha doin";
	string::iterator it = search_n(a.begin(), a.end(), 2, 's'); 	// this searches for 2 consecutive 's' and returns pointer to first 's'
	cout<<*it<<endl;
	a.erase(it, it+3);				//erase
	a.insert(it, 3, 'x');			// insert 3 x's at it
	a.replace(it, it+2, 3, 'y');	//replace it to it+2 with 3 y's
	cout<<a<<endl;

	a = "durgesh";
	string b = "shegrud";
	cout<<is_permutation(a.begin(), a.end(), b. begin())<<endl;
	replace(a.begin(), a.end(), 'r', ' ');	// this is algorithm replace and it replaces all the instances of 'r' to ' '
	cout<<a <<endl;
	transform(a.begin(), a.end(),
		a.begin(),
		[](char c){
			if(c < 'n')
				return 'a';
			else
				return 'z';
		});

	cout<<a<<endl;

	rotate(b.begin(), b.begin()+2, b.end());
	cout<<b<<endl;

	// u16string c = "d";
	// cout<<c<<endl;
}