#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	string a = "durgesh";
	cout<<a[0]<<endl;
	cout<<a.size()<<endl;
	cout<<a.capacity()<<endl;
	cout<<a<<endl;
	cout<<a.at(1)<<endl;
	cout<<a.front()<<endl<<a.back()<<endl;	// front and back are c++11

	a.push_back('h');	// push and pop are available only from the back
	a.pop_back();
	cout<<a<<endl;

	// walking the string via iterator
	for(string::iterator it = a.begin(); it != a.end(); ++it){
		if(*it == 'd')
			*it = 'c';	// since we are not using const_itetator we can modify the string also
		cout<<*it;
	}

	cout<<endl;

	string f(a.begin()+1, a.begin()+3);		// copies in range [strart, end)
	cout<<f<<endl;

	string g({'a','b','d'});
	cout<<g<<endl;		// intializer list
	g.append(a);
	cout<<g<<endl;
	g.insert(2," mountain", 4);
	cout<<g<<endl;
	g.replace(2, 3, a, 3, 3); 	// replace 3 chars from g[2] with 3 chars from a[3]	
	cout<<g<<endl;
	g.erase(2,4); 		//erases 4 chars from position 2
	cout<<g<<endl;	
	cout<<g.substr(2,4)<<endl;		//prints substring from position 2 and size 4
	cout<<"c string: "<<(g.c_str())[5]<<endl;



	string b("choudhary", 5);	// here it takes it as length to consider
	string c("choudhary", 5, 4);	// here 2nd arg is start index and 3rd is length
	cout<<b<<endl;
	cout<<b.capacity()<<endl;	
	cout<<c<<endl;

	string d;

	cout<<d.capacity()<<endl;	//default capacity
	d.append("news");
	cout<<d<<" "<<d.capacity()<<endl;	//default capacity

	string e(5,'a');	// this function takes a character and repeats it number of times based on first argument
	cout<<e<<endl;


}