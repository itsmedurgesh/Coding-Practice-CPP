#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_odd(int n){ return (n%2==1);}

int main(){
	vector<int> v({12,3,6,1,76});
	vector<int>::iterator it = min_element(v.begin(), v.end());

	sort(v.begin(), it);  // sorts in range [vbegin, end)
	reverse(it, v.end());	// reverse the container in range [it vend)

	vector<int> v1;
	v1.insert(v1.end(), it, v.end());	//efficient and safe
	// this is efficient because it copies all at once but insert_iterator inserts one by one

	it = find_if(v.begin(), v.end(), is_odd);

	cout<<"first odd is "<<*it<<endl;

	for(int i:v)
		cout<<i<<" ";

	cout<<endl;
	int a[] = {6,9,2,4,8,1};

	sort(a+1, a+5);
	for(int i:a)
		cout<<i<<" ";


}