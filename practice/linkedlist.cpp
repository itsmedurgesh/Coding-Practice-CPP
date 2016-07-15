#include <iostream>

using namespace std;

class Node{
public:
	int data;
	Node *next;

	Node(int d): data(d), next(NULL){}
};

class List{
	Node *front = NULL, *end = NULL;
public:
	void insert(int d){

		Node p(d);

		if(front == NULL){
			front = &p;
			return;
		}
		else{
			p.next = front;
			front = &p;
		}
	}

	void del();
	void print();
	
};


void List::del(){
	Node* p = front;
	front = front->next;
	delete p;
}

void List::print(){
	Node *p = front;
	while(p != NULL){
		cout<<p->data<<" ";
		p = p->next;
	}
}

int main(){

	List l;
	l.insert(32);l.print();
	l.insert(12);l.print();
	l.insert(22);l.print();
	l.insert(44);
	l.print();
}