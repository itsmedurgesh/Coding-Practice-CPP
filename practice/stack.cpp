#include <iostream>

using namespace std;

class Node{
	
public:
	int data;
	Node *next;
	Node(int d): data(d), next(NULL){}
};

class Stack{
public:
	Node *top;
	Stack():top(NULL){}

	void insert(int d){
		Node *tmp;
		tmp = new Node(d);
		tmp->next = top;
		top = tmp;	
	}

	void print(){
		Node *p = top;
		while(p != NULL){
			cout<<p->data<<endl;
			p = p->next;
		}
	}

	void del(){
		if(top != NULL){
			Node *tmp  = top;
			top = top->next;
			delete tmp;
		}

	}
};


int main(){
	
	Stack s;
	s.insert(12);
	// s.print();
	s.insert(32);
	s.del();
	s.insert(65);
	s.print();

}