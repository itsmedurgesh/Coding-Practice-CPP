#include <iostream>

//TODO: define Node and map
using namespace std;

typedef map<Node*, Node*> Nodemap;

Node* copy_recursive(Node* cur, Nodemap &nodemap){
	if(cur==NULL){
		return NULL;
	}

	Nodemap::iterator i = nodemap.find(cur);
	if(i != nodemap.end())
		return i->second();

	Node* node = new Node;
	nodemap[cur] = node;

	node->ptr1 = copy_recursive(cur->ptr1, nodemap);
	node->ptr2 = copy_recursive(cur->ptr2, nodemap);
	return node;
}

Node* copy_structure(Node* root){
	Nodemap nodemap;
	return copy_recursive(root, nodemap);
}

int main(){

}