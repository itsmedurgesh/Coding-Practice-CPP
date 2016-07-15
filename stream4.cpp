#include <iostream>

using namespace std;

int main(){
	// IO operation:
	//	formatting the data -- stream
	// communicating the data to external devices -- stream buffer

	cout<< 34;
	streambuf* pbuf = cout.rdbuf();		// getting stream buffer of cout

	ostream mycout(pbuf);			// assigning same stream buffer to new stream
	mycout << 23; 	// this will print 23 to stdout

	//changing the properties of mycout
	mycout.setf(ios::showpos); // shows positive sign
	mycout.width(20);
	mycout << 20		// "                 +12"
	cout<<20;			// "20"
	// this can be useful when we want to change format for some particular outputs

	ofstream of("mylog.txt");

	streambuf* origbuf = cout.rdbuf();	// saving original stream buffer so we can reassign it to cout
	cout.rdbuf(of.rdbuf()); // this assigns stream buffer of 'of' to cout
	cout<< "hello" << endl;	// "hello" will be printed in mmylog.txt

	cout.rdbuf(origbuf);
	cout<<"goodbye";	// goes stdout

	// ** another way to access stream buffer is through stream buffer iterator
	istreambuf_iterator<char> i(cin);
	ostreambuf_iterator<char> o(cout);

	while(*i != 'x'){
		*o = *i;
		++o;
		++i;
	}	// this code will take everything from stdin and send it to stdout unless 'x' is entered

	// using copy iterator 
	copy(istreambuf_iterator<char>(cin), istreambuf_iterator<char>(), ostreambuf_iterator<char>(cout));



}