#include <iostream>
#include <algorithm>

class Node{
    public:
        int key;
        int height;
        Node *left, *right;

        Node(int d): key(d), height(1), left(NULL), right(NULL){}
        Node(){}
};

class AVL{
    public:
        Node * root;
        AVL(): root(NULL) {}

        int getheight(Node * root){
            if(!root) return 0;
            else return root->height; 
        }

        Node * leftrotate(Node * root){
            Node * y = root->right;
            Node * T = y->left;

            root->right = T;
            y->left = root;
            
            root->height = 1 + std::max(getheight(root->left), getheight(root->right));
            y->height =  1 + std::max(getheight(y->left), getheight(y->right));

            return y;
        }


        Node * rightrotate(Node * root){
            Node * y = root->left;
            Node * T = y->right;

            y->right = root;
            root->left = T;

            root->height = 1 + std::max(getheight(root->left), getheight(root->right));
            y->height =  1 + std::max(getheight(y->left), getheight(y->right));

            return y;
        }

        Node * insert(Node * root, int x){
            if(!root) return new Node(x);
            
            if(root->key < x) root->right = insert(root->right, x);
            else if(root->key > x) root->left = insert(root->left, x);
           
            root->height = 1 + std::max(getheight(root->left), getheight(root->right));

            int bf = balancefactor(root);
            if(bf > 1 && x < root->left->key) //LL case
                root = rightrotate(root);
            else if(bf > 1 && x > root->left->key){   //LR case
                 root->left = leftrotate(root->left);
                 root = rightrotate(root);
            }
            else if(bf < -1 && x > root->right->key){
                // RR case
                root = leftrotate(root);
            }
            else if(bf < -1 && x < root->right->key){
                //RL case
                root->right = rightrotate(root->right);
                root = leftrotate(root);
            }
            return root;
        }

        Node * succ(Node * root){
            if(!root) return root;
            if(!root->right) return root;
            Node * t = root->right;
            while(t->left) t = t->left;
            return t;
        }

        Node * remove(Node * root, int x){
            if(!root) return NULL;      
            if(root->key < x) root->right = remove(root->right, x);
            else if(root->key > x) root->left = remove(root->left, x);
            else{
                
                if(!root->left || !root->right){
                    Node * child = root->left ? root->left : root->right;
                    if(!child){
                        child = root;
                        root = NULL;
                    }
                    else *root = *child;
                    delete child;
                }
                else{
                    Node *s = succ(root);
                    root->key = s->key;
                    root->right = remove(root->right, s->key);
                }

            }

            if(!root) return NULL;

            root->height = 1 + std::max(getheight(root->left), getheight(root->right));
            int bf = balancefactor(root);

            if(bf > 1 && balancefactor(root->left) >= 0) //LL case
                root = rightrotate(root);
            else if(bf > 1 && balancefactor(root->left) < 0){   //LR case
                 root->left = leftrotate(root->left);
                 root = rightrotate(root);
            }
            else if(bf < -1 && balancefactor(root->right) <= 0){
                // RR case
                root = leftrotate(root);
            }
            else if(bf < -1 && balancefactor(root->right) > 0){
                //RL case
                root->right = rightrotate(root->right);
                root = leftrotate(root);
            }


            return root;
        }

        void inorder(Node * root){
            
            std::vector<Node *> curr, next;
            curr.push_back(root);
            while(!curr.empty()){
                for(Node *t: curr){
                    std::cout<<t->key<<" ";
                    if(t->left) next.push_back(t->left);
                    if(t->right) next.push_back(t->right);
                }

                std::cout<<"\n";
                curr.swap(next);
                next.clear();
            }
        }

        int balancefactor(Node *root){
            int lh = root->left ? root->left->height : 0;
            int rh = root->right ? root->right->height : 0;
            return  lh - rh;
        }
};

int main(){
   AVL a;
   a.root = a.insert(a.root, 10);
   a.root = a.insert(a.root, 20);
   a.root = a.insert(a.root, 30);
   a.root = a.insert(a.root, 40);
   a.root = a.insert(a.root, 50);
   a.root = a.insert(a.root, 25);
   a.inorder(a.root);
   std::cout<<"\n";
   a.root = a.remove(a.root, 30);
   a.root = a.remove(a.root, 50);
   a.inorder(a.root);
}
