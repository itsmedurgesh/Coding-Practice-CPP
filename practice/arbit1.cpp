#include <iostream>

using namespace std;

class Node{
	
public:
	int data;
	Node *next;
	Node(int d): data(d), next(NULL){}
};

class Queue{
public:
	Node *front, *back;
	Queue():front(NULL), back(NULL){}

	void insert(int d){
		Node *tmp;
		tmp = new Node(d);
		if(front == NULL){
			front = tmp;
			back = tmp;
		}
		else{
			back->next = tmp;
			back = tmp;
		}
	}

	void print(){
		Node *p =front;
		while(p != NULL){
			cout<<p->data<<endl;
			p = p->next;
		}
	}

	void del(){
		if(front != NULL){
			Node *tmp  = front;
			front = front->next;
			delete tmp;
		}
		else throw "empty Queue";
	}
};


int main(){
	
	Queue s;
	s.insert(12);
	// s.print();
	s.insert(32);
	s.del();
	s.insert(65);
	s.print();
	// s.del();
	// s.del();
	// s.del();
}