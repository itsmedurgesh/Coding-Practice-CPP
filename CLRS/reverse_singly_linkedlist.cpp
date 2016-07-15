//TODO: this has not been implemented properly but it has been implemented in java
#include <iostream>

using namespace std;

class node{
    public:
    int d;
    node *next;

    node(int d): d(d), next(NULL){ }
};

void insert(node ** head, int d){

    node t(d);

    if(*head == NULL){
        *head = &t;
        return;
    }

    node *t1 = *head;
    while(t1->next !=NULL) t1 = t1->next;

    t1->next = &t;

    return;
}


void print(node ** head){
    cout<<endl;
    node *t = *head;
    while(t->next != NULL){
        cout<<t->d<<" ";
        t = t->next;
    }
    
}

int main(){
    node *head = NULL;   
    insert(&head, 1);
    insert(&head, 4);
    insert(&head, 3);
    insert(&head, 7);
    print(&head);

}
