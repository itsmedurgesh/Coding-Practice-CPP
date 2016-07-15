#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	

	vector<int> v1({3,4});	// c++11 syntex for initializing a vector

	vector<int> v2({1,2,5,6,7});	

	copy(v1.begin(), v1.end(), v2.begin());		// for this to work length of v2 should be equal or more than v1
	// range is inferred by using first two arguments

	for(int i : v2)
		cout<<i<<" ";

	cout<<"that wsas v1"<<endl;



	vector<int>::iterator it = find(v2.begin(), v2.end(), 5);		//getting the position of 5

// insert iterator

	insert_iterator< vector<int> > i_itr(v2, it);		//creating the insert_iterator based on it position for v2

	copy(v1.begin(), v1.end(), i_itr);					//copyging v1 to v2 using insert_iterator

	// front_insert_iterator< vector<int> > fi_itr(v2);
	// copy(v1.begin(), v1.end(), fi_itr);

	for(it = v2.begin(); it!= v2.end(); ++it)
		cout<<*it<<" ";

// strem iterator

	vector<string> v3;

	copy(istream_iterator<string>(cin), istream_iterator<string>(), back_inserter(v3));
	copy(v3.begin(), v3.end(), ostream_iterator<string>(cout, "\n"));
// reverse iterator
	reverse_iterator<vector<string>::iterator> ritr;
		for(ritr = v3.rbegin(); ritr != v3.rend(); ++ritr)
			cout<<*ritr<<" ";


}
