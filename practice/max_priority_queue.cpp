#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
	int data;	
	Node(){}
	Node(int d): data(d){}
};

//-------------------------

class PriorityQueue{
private:
	vector<Node> v;
	void shiftup(int i);
	void shiftdown(int i);

public:
	void insert(Node x);	
	Node maximum();
	Node extract_max();
	void increase_key(Node x, int k);
	void printqueue();
};

void PriorityQueue::shiftup(int i){
	if(i == 0) return;
	int p = (i-1)/2;
	if(v[p].data < v[i].data){
		Node t = v[p];
		v[p] = v[i];
		v[i] = t;

		shiftup(p);
	}
}

void PriorityQueue::shiftdown(int i){

	if(i >= v.size()) return;

	int l = 2*i+1;
	int r = 2*i+2;

	int max;

	if(l < v.size() && v[l].data > v[i].data)
		max = l;
	else
		max = i;

	if(r < v.size() && v[r].data > v[max].data)
		max = r;

	if(max != i){
		Node t = v[i];
		v[i] = v[max];
		v[max] = t;

		shiftdown(max);
	}
}


void PriorityQueue::insert(Node x){
	v.push_back(x);
	shiftup(v.size()-1);
}

Node PriorityQueue::maximum(){
	return v[0];
}

Node PriorityQueue::extract_max(){
	Node t = v[0];
	v[0] = v[v.size()-1];
	v.pop_back();
	shiftdown(0);

	return t;
}


// this takes O(n) because we have to find the node whose priority we have to increase
void PriorityQueue::increase_key(Node x, int k){
	int id = -1;
	for(int i = 0; i<v.size(); ++i){
		if(v[i].data == x.data){
			id = i;
			break;
		}
	}

	if(id == -1){
		cout<<"index not found"<<endl;
		return;
	}

	// cout<<"id is "<<id;

	if(v[id].data >= k){
		cout<<"new priority is not more than previous one"<<endl;
		return;
	}

	v[id].data = k;
	shiftup(id);
}

void PriorityQueue::printqueue(){
	for(Node t:v){
		cout<<t.data<<" ";
	}
	cout<<endl;
}

int main(){
	PriorityQueue q;
	q.insert(Node(1));
	q.insert(Node(2));
	q.insert(Node(3));
	q.insert(Node(4));
	q.insert(Node(5));
	q.insert(Node(6));
	q.insert(Node(7));
	q.insert(Node(8));
	q.printqueue();

	cout<<"maximum is "<<(q.maximum()).data<<endl;
	cout<<"maximum removed "<<(q.extract_max()).data<<endl;
	cout<<"maximum removed "<<(q.extract_max()).data<<endl;
	q.printqueue();

	cout<<"incresing key 1 to 19"<<endl;
	q.increase_key(Node(1), 19);
	q.printqueue();


}