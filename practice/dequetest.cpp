#include <iostream>
#include <deque>
using namespace std;

int main(){
	deque<int> q;
	q.push_back(1);
	q.push_back(12);
	q.push_front(22);
	q.push_back(3);

	for(deque<int>::iterator itr = q.begin(); itr != q.end(); itr++)
		cout<<*itr<<" ";

	for(int i=0; i<q.size(); i++)
		cout<<q[i] <<" ";
}