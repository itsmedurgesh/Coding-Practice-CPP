// this is minimal working example of a BST
// it supports insert, delete, search and print
#include <iostream>
#include <vector>

using namespace std;

class Node{
    public:
        int data;
        Node *left, *right;
        Node(int d): data(d), left(NULL), right(NULL) {}
};

class BST{
    public:
        Node * root;
        BST(): root(NULL){}
        BST(int x) {root = new Node(x);}

        bool search(int x){
            Node *t = root;
            while(t && t->data != x){
                if(t->data < x) t = t->right;
                else t = t->left;
            }
            if(t) return true;
            else return false;
        }

        bool insert(int x){
            if(!root) return root = new Node(x);
            Node *t = root;
            while(t->data != x){
                if(t->data < x && t->right) t = t->right;
                else if(t->data > x && t->left) t = t->left;
                else break;
            }
            if(t->data == x) return false;
            else{
                if(t->data < x) t->right = new Node(x);
                else t->left = new Node(x);
                return true;
            }
        }

        // remove can potentially change the root
        // it is easier to implement this way then to keep track of parent of the node we have to delete
        //
        //
        Node * remove(Node * root, int x){
            if(!root) return NULL;
            if(root->data < x) root->right = remove(root->right, x);
            else if(root->data > x) root->left = remove(root->left, x);
            else{
                if(!root->left) root = root->right;
                else if(!root->right) root = root->left;
                else{
                    Node *succ = root->right, *pre = root;
                    while(succ->left){
                        pre = succ;
                        succ = succ->left;
                    }

                    root->data = succ->data;
                    if(pre == root) pre->right = succ->right;
                    else{

                        if(succ->right) pre->left = succ->right;
                        else pre->left = NULL;
                    }
                    delete succ;     
                }
            }
            return root;
        }


        void print(){
            vector<Node*> curr, next;
            curr.push_back(root);
            while(!curr.empty()){
                for(auto t : curr){
                    cout<<t->data<<" ";
                    if(t->left) next.push_back(t->left);
                    if(t->right) next.push_back(t->right);
                }
                cout<<endl;
                curr.swap(next);
                next.clear();
            }
        }
};

int main(){
    BST b{7};
    b.insert(3);
    b.insert(11);
    b.insert(2);
    b.insert(6);
    b.insert(9);
    b.insert(16);
    b.print();
    b.root = b.remove(b.root, 2);
    b.root = b.remove(b.root, 11);
    b.insert(22);
    b.print();

}
