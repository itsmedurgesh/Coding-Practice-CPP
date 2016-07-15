#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

void p(int n){ cout<<n<<" "; }

int main(){
	set<int> s;
	s.insert(3);
	s.insert(12);
	s.insert(23);

	set<int>::iterator it;

	it = s.find(12);
	//cout<<*it<<endl;

	pair<set<int>::iterator, bool> ret = s.insert(4);
	cout<<*ret.first<<" "<<ret.second<<endl;

	s.insert(it, 9);

	s.erase(it);

	// every container has iterator and const_iterator. const_iterator can not be modified
	set<int>::const_iterator cit;
	for(cit = s.cbegin(); cit != s.cend(); ++cit){
		cout<<*cit<<" ";
	}


	cout<<endl;

	/* this for_each requires algorithm to be included 
	* this takes start and end const_iterator and a funtion and applies that function to all the elements in that range
	*/
	for_each(s.cbegin(), s.cend(), p);

	cout<<endl;

	for(int a: s)
		cout<<a<<" ";


}