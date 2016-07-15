#include <iostream>
using namespace std;

struct Interval{
    int low, high;
};

struct ITNode{
    Interval *i;
    int max;
    ITNode *left, *right;
};

ITNode * newNode(Interval i){
    ITNode *t = new ITNode;
    t->i = new Interval(i);
    t->max = i.high;
    t->left = t->right = NULL;
}

ITNode * insert(ITNode *root, Interval i){
    if(!root) return newNode(i);

    int l = root->i->low;

    if(i.low < l)
        root->left = insert(root->left, i);
    else
        root->right = insert(root->right, i);

    if(root->max < i.high) root->max = i.high;
    return root;
}

bool checkoverlap(Interval i1, Interval i2){
    return i1.low <= i2.high && i2.low <= i1.high;
}

Interval * overlapsearch(ITNode *root, Interval i){
    if(!root) return NULL;

    if(checkoverlap(*(root->i), i)) return root->i;

    if(root->left && root->left->max >= i.low) return overlapsearch(root->left, i);

    return overlapsearch(root->right, i);
}

void inorder(ITNode *root)
{
    if (root == NULL) return;

    inorder(root->left);

    cout << "[" << root->i->low << ", " << root->i->high << "]"
        << " max = " << root->max << endl;

    inorder(root->right);
}

// Driver program to test above functions
int main()
{
    // Let us create interval tree shown in above figure
    Interval ints[] = {{15, 20}, {10, 30}, {17, 19},
        {5, 20}, {12, 15}, {30, 40}
    };
    int n = sizeof(ints)/sizeof(ints[0]);
    ITNode *root = NULL;
    for (int i = 0; i < n; i++)
        root = insert(root, ints[i]);

    cout << "Inorder traversal of constructed Interval Tree is\n";
    inorder(root);

    Interval x = {6, 7};

    cout << "\nSearching for interval [" << x.low << "," << x.high << "]";
    Interval *res = overlapsearch(root, x);
    if (res == NULL)
        cout << "\nNo Overlapping Interval";
    else
        cout << "\nOverlaps with [" << res->low << ", " << res->high << "]";
    return 0;
}
