#include <iostream>


using namespace std;

int main(){
	cout<<34<<endl;		// 34
	cout.setf(ios::oct, ios::basefield);
	cout<<34<<endl;		// 42
	cout.setf(ios::showbase);
	cout<<34<<endl;		// 042
	cout.setf(ios::hex, ios::basefield);
	cout<<34<<endl;		//0x22
	cout.unsetf(ios::showbase);
	cout<<34<<endl;		//22
	cout.setf(ios::dec, ios::basefield);

	cout.width(10);
	cout<<34<<endl;		// "        34"
	cout.setf(ios::left, ios::adjustfield);
	cout<<34<<endl;		// "34        "


	//floating point value
	cout.setf(ios::scientific, ios::floatfield);
	cout<<340.1<<endl;		//3.4010000e+02

	cout.setf(ios::fixed, ios::floatfield);
	cout<<340.1<<endl;		//340.100000

	cout.precision(3);
	cout<<340.1<<endl;		//340.100

	int i;
	cin.setf(ios::hex, ios::basefield);
	cin>>i;		// takes input as hex i.e. if we enter 12 it will take it as 18
	cout<<i<<endl;

	cout.flags();

	ios::fmtflags f = cout.flags();		// returns current flags status
	cout.flags(ios::oct | ios::showbase);


	// ** Member functions for unformatted IO
	// Input
	ifstream inf("mylogfile");
	char buff[80];
	inf.get(buff, 80);	// reads upto 80 chars and save them into buff
	inf.getline(buff, 80); 	// reads upto 80 chars or a '\n'
	inf.read(buff, 20); 	// reads 20 chars
	inf.ignore(3); // this will ignore next 3 chars
	inf.peek(); // this will return char on top of the stream
	inf.unget();	// returns char back to the stream
	inf.get();		//
	inf.gcount(); 	// return the number of chars being read by last unformatted read

	//Output
	ofstream of("mylogfile");
	of.put('c'); // puts one char in to the stream
	of.write(buff, 6); // writes first 6 chars of buff into the stream
	of.flush(); // this will flush the output
	

}