#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main(){
	unordered_set<string> us = {"green", "yellow", "red"};

	// unordered_multiset is  same as unordered_set accept the points mentioned in multiset

	unordered_set<string>::const_iterator it = us.find("green");

	if(it != us.end())		// this check is important
		cout<<*it<<endl;

	us.insert(it, "blue");
	std::vector<string> v = {"pink", "purple"};

	us.insert(v.begin(), v.end());

	for(string s: us)
		cout<<s<<endl;

	cout<<"hash specific apis\n";
	cout<<"load_factor: "<<us.load_factor()<<endl;
	string x="red";
	cout<<x<<" is in bucket #"<<us.bucket(x)<<endl;
	cout<<"total buckets"<<us.bucket_count()<<endl;
}