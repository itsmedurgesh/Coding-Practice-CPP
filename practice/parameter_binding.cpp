#include <iostream>
#include <set>
#include <vector>		
#include <functional>	//for bind
#include <algorithm>	//for transform
#include <cmath>
using namespace std;

void add(int a , int b) { cout<<a+b<<" ";}

double Pow (int a, int b){ pow(a,b);}

int main(){
	set<int> s = {2,3,4,5};
	vector<int> v;

	transform(s.begin(), s.end(), 
		back_inserter(v),
		bind(multiplies<int>(), placeholders::_1, 10));


	for_each(v.begin(), v.end(), bind(add, placeholders::_1, 2));

	cout<<endl;

	for(int i: v)
		cout<<i<<" ";

	
	cout<<endl;
	
	vector<int> v1;
	auto f = function<double (double, double)> (Pow);
	transform(v.begin(), v.end(), 
		back_inserter(v1),
		bind(f, placeholders::_1, 2));

	for(int i: v1)
		cout<<i<<" ";

	// another example of bind
	cout<<endl;
	set<int> s2 = {3,1,75,7,12};
	vector<int> v2;
	transform(s2.begin(), s2.end(),
		back_inserter(v2),
		// bind(logical_or<bool>(),
		// 	bind(greater<int>(), placeholders::_1, 50),
		// 	bind(less<int>(), placeholders::_1, 5)
		// 	)
		// bind(greater_equal<int>(), placeholders::_1, 10)
		[](int x){return x>20 || x < 10;}   // this is a lambda function
		);
	//** alright this one is giving some strange results
		for(int i=0; i<v2.size(); ++i)
			cout<<v2[i]<<" ";

}
