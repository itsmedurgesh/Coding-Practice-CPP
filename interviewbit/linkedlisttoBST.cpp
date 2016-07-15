#include <iostream>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

TreeNode* toBSTi(ListNode **headref, int n);
TreeNode* toBST(ListNode *A){
    int n = 0;
    ListNode* t = A;
    while(t){++n; t=t->next;}

    return toBSTi(&A, n);
}

TreeNode* toBSTi(ListNode **headref, int n){
    if(n <= 0) return NULL;

    TreeNode *left = toBSTi(headref, n/2);

    TreeNode *root = new TreeNode((*headref)->val);
    root->left = left;

    *headref = (*headref)->next;

    root->right = toBSTi(headref, n-n/2-1);

    return root;
}

void print(TreeNode *root){
    if(root->left) print(root->left);
    cout<<root->val<<" ";
    if(root->right) print(root->right);
}
int main(){
    ListNode *a = new ListNode(7);
    a->next = new ListNode(12);
    a->next->next = new ListNode(1);
    a->next->next->next = new ListNode(2);
    ListNode *b = new ListNode(65);
    b->next = a;
    a = b;
    print(toBST(a));
}
