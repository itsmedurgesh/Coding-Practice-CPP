#include <iostream>
#include <map>

using namespace std;

int main(){
	map<char,int> m;

	m.insert(pair<char, int>('a', 100));
	m.insert(make_pair('b', 200));

	map<char, int>:: iterator it;
	it = m.begin();
	m.insert(it, pair<char, int>('d',300));	//here it is just a hint

	it = m.find('d');	//O(log n)

	for(it = m.begin(); it!= m.end(); it++)
		cout<<it->first<<" "<<(*it).second<<endl;
	
}