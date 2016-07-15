#include <iostream>
#include <fstream>	// fstream is needed whenever fle operation is needed

using namespace std;

int main(){
	cout<<"hello"<<endl;	//C++ I/O library --stream
	// cout: global object of ostream ( typedef basic_ostream<char> ostream)
	// <<: ostream& ostream::operator<<(string s);
	// endl: for now its '\n' + flush op

	// this stream provides serial access
	// cout[4] is not valid

	{	// the code is inside the block so we don't have to worry about closing of 'of' ofstream
		ofstream of("myfile.txt");		

		of << "this is a line" << endl;
		of << 124 << endl;
		of << 2.3 << endl;
		// of << bitset<8>(14) << endl; // writes 00001110
		// of << complex<int>(2,3)<<endl;	//(2,3)
	} //RAII 

	//IO operation;
	// formatting the data  <----->  communicating the data with external devices 
	// Software Engineer Principle: Low coupling -> reusability 

	{
		ofstream of("myfile.txt", ofstream::app);	// move the pointer to the end of the file
		of<< "Honesty is thee best policy.."<<endl;
	}

	{
		ofstream of("myfile.txt", ofstream::in | ofstream::out);
		of.seekp(10, ios::beg);	// move pointer 10 chars from the begining
		of << "12334";
		of.seekp(-5, ios::end);
		of<<"nothing really matters is a stupid quote..";
		of.seekp(-5, ios::cur);// move the pointer 5 chars before the current position
	}

	ifstream inf("myfile.txt");
	int i;
	inf>>i; // reads one word 
	// Error status: goodbit, badbit, failbit, eofbit
	inf.good(); 	// everything is okay goodbit == 1
	inf.bad();		// non recoverable error badbit == 1
	inf.fail(); 	// failed stream operation. generally recoverable. failebit == 1 and badbit == 1
	inf.eof();		// end of file eofbit == 1
	inf.clear();	// clears all error status bits; same as clear(ios::goodbit);
	inf.clear(ios::badbit); // sets badbit = 1 and all the other bits to 0

	inf.rdstate(); // reads the current status flags
	inf.clear(inf.rdstate() & ~ios::failbit);	// clears the failbit only 

	if(inf)			//equivalent to if(!inf.fail())
		cout<<"read successful";

	if(inf>>i)
		cout<<"read successful";

	//handle the errors with exceptions
	inf.exceptions(ios::badbit|ios::failbit);
	//when failbit ot badbit is set to 1 exception of ios::failure will be thrown
	//when eofbit is set to 1 no exception will be thrown

	inf.exceptions(ios::goodbit);	// no exception

}