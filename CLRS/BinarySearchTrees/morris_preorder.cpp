// IMP: here special links that are being made for morris like algo are not being destroyed
// hence this algorithm can be considered Wrong as it modifies tree in final state
#include <iostream>

using namespace std;

class node{
    public:
        int data;
        node *left, *right;

        node(int d): data(d), left(NULL), right(NULL) {}
};

void preorder(node *root){
    node *cur, *pre;
    if(!root) return;

    cur = root;
    while(cur){
        cout<<cur->data<<" ";
        if(!cur->left){
            cur = cur->right;
        }
        else{
            pre = cur->left;
            while(pre->right && pre->right != cur) pre = pre->right;
            if(!pre->right){
                // IMP: since current node is already traversed in preorder we can skip it and move to its right node
                pre->right = cur->right;
                cur = cur->left;
            }
            else{       // this detects whether left subtree has been traversed
                pre->right = NULL;
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
    root->right->left = new node(13);
    root->right->right = new node(17);
    preorder(root);
}
