#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main(){
	unordered_map<string, int> um = {{"green", 100}, {"yellow",200}, {"red",400}};

	// unordered_multiset is  same as unordered_set accept the points mentioned in multiset

	cout<<um["red"]<<endl;		// this does not perform range check
	cout<<um.at("red")<<endl;	// this performs range check and throws exception

	/** this above subscipt operator provides a write operation and hence if the map is defined as const (say in a function)
	* then this would generate an error 
	even cout<<um["red"] would generate an error
	*/	

	unordered_map<string, int>::const_iterator it = um.find("green");

	if(it != um.end())		// this check is important
	 	cout<<it->first<<" "<<it->second<<endl;

	um.insert(make_pair("blue",500));
	std::vector<pair<string, int>> v = {{"pink",600}, {"purple",800}};

	um.insert(v.begin(), v.end());

	for(pair<string, int> p: um)
		cout<<p.first<<" " <<p.second<<endl;

	cout<<"hash specific apis\n";
	cout<<"load_factor: "<<um.load_factor()<<endl;
	string x="red";
	cout<<x<<" is in bucket #"<<um.bucket(x)<<endl;
	cout<<"total buckets"<<um.bucket_count()<<endl;
}