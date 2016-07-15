#include <iostream>
#include <set>

using namespace std;

int main(){
	multiset<int> s;
	s.insert(3);
	s.insert(12);
	s.insert(23);
	s.insert(23);

	multiset<int>::iterator it;

	it = s.find(12);
	cout<<*it<<endl;

	it = s.insert(4);
	//cout<<*ret.first<<" "<<ret.second<<endl;

	s.insert(it, 9);

	s.erase(it);

	for(int a: s)
		cout<<a<<" ";


}