#include <iostream>

using namespace std;

class node{
    public:
    int data;
    node *left, *right;
    
    node(int d): data(d), left(NULL), right(NULL) {}
};

void inorder(node *root){
    node *cur, *pre;
    if(!root) return;

    cur = root;
    while(cur){
        if(!cur->left){
            cout<<cur->data<<" ";
            cur = cur->right;
        }
        else{
            pre = cur->left;
            while(pre->right && pre->right != cur) pre = pre->right;
            if(!pre->right){
                pre->right = cur;
                cur = cur->left;
            }
            else{       // this detects whether left subtree has been traversed or not
                pre->right = NULL;
                cout<<cur->data<<" ";
                cur = cur->right;
            }
        }
    }
}

int main(){
    node *root = new node(12);
    root->left = new node(8);
    root->left->left = new node(3);
    root->left->right = new node(10);
    root->right = new node(15);
    inorder(root);
}
