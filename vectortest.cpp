#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<int> v;
	v.push_back(1);
	v.push_back(12);
	v.push_back(3);

	for(vector<int>::iterator itr = v.begin(); itr != v.end(); itr++)
		cout<<*itr<<" ";

	for(int it: v)
		cout<<it <<" ";
}