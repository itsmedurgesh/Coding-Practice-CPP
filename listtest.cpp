#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main(){
	list<int> l, l1;
	l.push_front(12);
	l.push_front(1);
	l.push_back(23);
	// list<int>::iterator it = find(l.begin(), l.end(), 12); // function not availables
	//l.insert(3, 34);

	list<int>::iterator itr;

	itr = l.begin();
	advance(itr,1);
	l.insert(itr, 10);
	advance(itr, -1);

	l1.splice(l1.begin(), l, itr, l.end());	//transferred from position itr to end of l to l1

	for(itr = l1.begin(); itr != l1.end(); itr++)
		cout<<*itr<<" ";
	// for(int i=0; i<l.size(); i++)
	// 	cout<<l.at(i)<<" ";

}