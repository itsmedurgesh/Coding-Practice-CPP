#include <iostream>
#include <string>

using namespace std;

int main(){
	string a;

	// cin>>a;	// this does not store whole line 
	// getline(cin, a);
	// getline(cin, a, ';'); // this sets a delimiter ; i.e. reads from cin and assigns it to a until ; is found
	//cout<<a;

	cout<<to_string(8)<<endl;
	cout<<to_string(8.2e-7)<<endl;
	cout<<to_string(0xa4)<<endl;		// this converts number to string representation
	cout<<to_string(010)<<endl;			// this also converts octal number

	// string to number
	a  = "190";
	int i = stoi(a);
	cout<<i<<endl;
	a = "190 hello";	// would not number does not start from begining
	size_t pos;			// would not work with int
	i = stoi(a, &pos);	// this converts string to number until where it is possible and then assigns next index to pos
	cout<<i <<" "<< pos<<endl;

	i = stoi("ass", &pos, 16);	// this would look for hex number hence i =  10
	cout<<i <<" "<< pos<<endl;

	/* ** other conversion functions 
	* 	stol, stof, stod, etc
	*/
}