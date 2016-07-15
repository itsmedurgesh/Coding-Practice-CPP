#include <iostream>
#include <vector>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}

  };

TreeNode* makeTree(const vector<int> &A, int start, int end){
    if(start > end) return NULL;
    
    int mid = (start+end)/2;
    TreeNode* parent = new TreeNode(A[mid]);
    parent->left = makeTree(A, start, mid-1);
    parent->right = makeTree(A, mid+1, end);
    
    return parent;
}

void printTree(TreeNode *root){
    if(root == NULL) return;

    printTree(root->left);
    cout<<root->val<<" ";
    printTree(root->right);
}

TreeNode* sortedArrayToBST(const vector<int> &A) {
    
    TreeNode* root = makeTree(A, 0, A.size()-1);
    
    return root;
}

int main(){
    vector<int> v = {1,3,5,23,65,87,9786};
    TreeNode *root = sortedArrayToBST(v);
    printTree(root);
}
