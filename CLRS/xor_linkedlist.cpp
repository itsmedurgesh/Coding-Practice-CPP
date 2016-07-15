
#include <iostream>

using namespace std;

class node{
    public:
    int d;
    node * next;

    node(int d): d(d), next(NULL){}
};

node * XOR(node *a, node *b){
    return (node *)(a ^ b);
}

class xorlist{
    
    public:
    node *head = NULL, *tail=NULL;
    void insert(int d){
            node t(d);
        if(head == NULL){
            head = &t;
            tail = head;
        }
        else{
            t.next = XOR(tail, NULL);
            node * nxp = XOR(tail->next, NULL);
            tail->next = XOR(&t, nxp);
            tail = &t;
        }
    }

    void print(){
        node *t = head;
        node *pre, *next;
        pre = NULL;
        while(t != NULL){
            next = XOR(t->next,pre);
            cout<<t->d<<" ";
            pre = t;
            t = next;
        }
    }
};


int main(){
    xorlist a;
    a.insert(3);
    a.insert(23);
    a.print();
}


