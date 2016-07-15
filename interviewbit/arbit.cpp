#include <iostream>
using namespace std;
class node{
    public:
    int d;
    node(int d): d(d){}
};

void add(node *root, node *r){
    if(!root) root = r;
}

int main(){
    node *root = NULL;
    node *a = new node(4);
    add(root, a);
    cout<<root->d;
}

