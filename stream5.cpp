#include <iostream>

using namespace std;

int main(){
	stringstream ss;	// Stream without IO operation	-- read/write of strings
	/* ** for better type safety use and readability
	* ostringstream -- formatted output
	* istringstream -- formatted input
	*/

	ss<<89<<" Hex: "<<89<<" Oct: "<<oct<<89<<endl;

	cout<<ss.str()<<endl;	//	89 Hex: 59 Oct: 131

	int a, b, c;
	string s1;

	ss >> hex >> a;		//	formatted input: it works token by token. seperated by whitespaces
	// a == 137
	ss >> s1; 		// s1 == "Hex:"
	ss >> dec>> b;	// b == 59

	ss.ignore(6);	//this will ignore next six chars	" Oct: "
	ss>>oct>>c;		// c == 89

}