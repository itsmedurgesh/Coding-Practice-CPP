#include <iostream>

using namespace std;

/* endl signature
	ostream& endl(ostream& sm){		// this has special name called Manipulator
		sm.put('\n');
		sm.flush();
		return sm;
	}
*/

/* operator for endl <<
	ostream& ostream::operator<<(ostream& (*func)(ostream&)){
		return (*func)(*this);
	}
*/



int main(){
	cout<<"hello"<<endl;		// it is \n and flush
	// endl is a function

	cout<<ends;		// inserts a '\0' null character
	cout<<flush; 	// flushes the stream
	cin >> ws; 		// read and discard white spaces

	cout <<setw(8)<<left<<setfill('_')<<99<<endl;	// sets width as 8 and makes it left aligned and then fills empty space with '_'
	cout << hex<< showbase<< 14; //prints 0xe
}