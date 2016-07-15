#include <iostream>
#include <string>

using namespace std;

int main(){
	string a = "durgesh";
	char buff[20];
	string b;

	unsigned int len = a.copy(buff, 4, 1);		// here case is opposite first arg is buff to copy 2nd is length and 3rd is start index
		// this copies to char array

	cout<<buff<<endl;

	a = "this is test string and we have to find something";
	int found = a.find("string");
	cout<<found<<endl;
	found = a.find("string", 45);	// this will start the search at a given index and if not found gives -1
	cout<<found<<endl;
	found = a.find("strigh", 1, 4);	/// this will start at 1 and search for 4 chars match
	cout<<found<<endl;
	found = a.find_first_of("durges");	// this will search for first occurence of alphabets from the given string
	/// **overloaded methods are same of find
	cout<<found<<endl;

	found = a.find_last_of("dur");	// finds the last occurence from alphabets of given string
	cout<<found<<endl;

	found = a.find_first_not_of("durgest");	// first occurence of char not in 
	cout<<found<<endl;

	found = a.find_last_not_of("durgest");	// last occurence of char not in 
	cout<<found<<endl;

	a = "durgesh";
	b = "choudhary";
	cout<<b.compare(a)<<endl;	
	// compare function compares two strings and negative if this string comes before given string in lexicographical listing 
	// 0 if same position and positive if after the given string

	cout<< (b < a)<<endl;	// we can use direct comparison which does under the hood comparison
	cout<<b.compare(3, 2, a)<<endl;	

}