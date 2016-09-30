#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <tuple>
#include <algorithm>

enum color {red, black};

class Node{
    public:
        int key;
        color c;
        Node *p, *l, *r;
        Node(int k){
            key = k;
            p = NULL;
            l = NULL;
            r = NULL;
            c = red;
        }
};

class RBtree{
    public:
        Node *root, *nil;
        RBtree(){
            // nil is the sentinel and it has color black
            nil = new Node(-1);
            nil->c = black;
            root = nil;
        }

        void insert(int key){

            // inserting in empty tree
            if(root == nil){
                root = new Node(key);
                root->c = black;
                root->l = nil;
                root->r = nil;
                return;
            }
            
            Node * t = root;
            
            // finding the apt place to add just as in normal bst
            while(t){
                if(t->key == key) return;
                if(key < t->key && t->l != nil) t = t->l;
                else if(key > t->key && t->r != nil) t = t->r;
                else break;
            }

            //inserting new node t1 at the apt place of t
            Node *t1 = new Node(key);
            t1->l = nil;
            t1->r = nil;
            if(key < t->key) t->l = t1; 
            else t->r = t1;
            t1->p = t;

            satisfy(t1);
        }

        Node * uncle(Node * node){
            if(node->p->p->l == node->p) return node->p->p->r;
            else return node->p->p->l;
        }

        void satisfy(Node *node){
            // reached the root so just make root black if it is not already black
            if(!node->p){ node->c = black; return;}
            
            // parent is already black so no need to worry
            if(node->p->c == black) return;
            
            Node * u = uncle(node);
            Node * p = node->p;
            Node * g = node->p->p;

            // if uncle is red then recolor parent and uncle and shift red to the grandparent for fixing further
            if(u->c == red){
                u->c = black;
                p->c = black;
                if(g != root) g->c = red;
                satisfy(g);
            }
            else{
            // here rotation is needed
                if(node == p->l && p == g->l){
                    //LL case
                    rightrotate(g);
                    p->c = black;
                    g->c = red;
                }
                else if(node == p->r && p == g->l){
                    //LR case
                    leftrotate(p);
                    rightrotate(g);
                    node->c = black;
                    g->c = red;
                }
                else if(node == p->l && p == g->r){
                    // RL case
                    rightrotate(p);
                    leftrotate(g);
                    node->c = black;
                    g->c = red;
                }
                else if(node == p->r && p == g->r){
                    // RR case
                    leftrotate(g);
                    p->c = black;
                    g->c = red;
                }
            }            
        }


        void rightrotate(Node *node){
            Node * parent = node->p;
            Node * left = node->l;

            // setting parent to appropriately

            if(parent){
                if(parent->l == node) parent->l = left;
                else parent->r = left;
                left->p = parent;
            }
            // if parent is NULL that means we are rotating at root and hence we need to update root
            else{
                root = left;
                root->p = NULL; 
            } 
            node->p = left;
            
            // shifting left's right child to node
            node->l = left->r;
            left->r->p = node;
            
            left->r = node;

            
        }

        void leftrotate(Node *node){
            Node * parent = node->p;
            Node * right = node->r;

            if(parent){
                if(parent->l == node) parent->l = right;
                else parent->r = right;
                right->p = parent;
            }
            else{
                root = right; 
                root->p = NULL;
            } 
            node->p = right;

            // shifting right's left child to node
            node->r = right->l;
            right->l->p = node;

            right->l = node;
        }


        void print(){
            std::vector<Node*> curr, next;

            curr.push_back(root);

            while(!curr.empty()){
                for(Node * t: curr){
                    std::cout<<t->key<<"("<<t->c<<") ";
                    if(t->l) next.push_back(t->l);
                    if(t->r) next.push_back(t->r);
                }
                std::cout<<"\n";
                curr.swap(next);
                next.clear();
            }
        }

        Node * findsucc(Node * node){
            if(node->r == nil) return node;
            Node * t = node->r;
            while(t->l != nil) t = t->l;
            return t;
        }

        void remove(Node * node, int d){
            if(root == nil) return;
            if(d < node->key) remove(node->l, d);
            else if(d > node->key) remove(node->r, d);
            else{
                Node * todelete = node;
                if(node->r != nil) todelete = findsucc(node);
                if(node != todelete){
                    node->key = todelete->key;
                    remove(node->r, todelete->key);
                }
                else{
                    Node * left = node->l;
                    // node is black with the red left child
                    if(left != nil){
                        node->key = left->key;
                        node->l = nil;
                        delete left;
                    }

                    //node is leaf
                    else{

                        if(node == root){
                            root = nil;
                            delete node;
                            return;
                        }
                        
                        // if node is black deleting will create double black node hence needs to fixed up
                        if(node->c == black) fixupdelete(node);

                        // updating parent pointer to nil node
                        if(node->p->l == node) node->p->l = nil;
                        else node->p->r = nil;

                        // free the node
                        delete node;
                    }
                }
            }
        }

        void fixupdelete(Node * node){
            // if node is root simply color it black and return
            if(node == root) {
                root->c = black;
                return;
            }

            bool isright = (node == node->p->r);

            if(isright){
                Node *a = node->p;
                
                Node *b = a->l;
                
                if(a->c == red){
                    
                    if(b->l->c == red){
                    //case 1.1 with LL case
                        rightrotate(a);
                        b->c = red;
                        a->c = black;
                        b->l->c = black;
                    }
                    else if(b->r->c == red){
                    //case 1.1 with LR case
                        leftrotate(b);
                        rightrotate(a);
                        a->c = black;
                    }
                    else{
                    //case 1.2 b has no child with is red
                        a->c = black;
                        b->c = red;
                    }
                }
                else{
                    if(b->c == red){
                        Node *cc = b->r;
                        // case 2.1.1 a is black b is red and c has some child which is red
                        if(cc->l->c == red || cc->r->c == red){
                            // here instead of left child right child is red and left child is black so we rotate left
                            // and recolor and hence new cc has its left child as red which fits our solution
                            if(cc->l->c == black && cc->r->c == red){
                                leftrotate(cc);
                                cc = b->r;
                                cc->c = black;
                                cc->l->c = red;
                            }
                            Node *d = cc->l;
                            leftrotate(b);
                            rightrotate(a);
                            if(d->c == red) d->c = black;
                        }
                        // case 2.1.2 a is black b is red and does not have a red child
                        else{
                            rightrotate(a);
                            b->c = black;
                            cc->c = red;
                        }
                    }
                    else{
                        if(b->l->c == red){
                        // case 2.2.1 a is black b is black and has left child as red
                            rightrotate(a);
                            b->l->c = black;
                        }
                        else if(b->r->c == red){
                        // case 2.2.1 a is black b is black and has right child as red
                            Node * cc= b->r;
                            leftrotate(b);
                            rightrotate(a);
                            cc->c = black;
                        }
                        else{
                        //case 2.2.2 a is black b is black and does not have a red child
                            b->c = red;
                            fixupdelete(a);
                        }
                    }
                }
            
            }
            else{
                Node *a = node->p;
                Node *b = a->r;

                if(a->c == red){
                    //case 1.1
                    if(b->r->c == red){
                        leftrotate(a);
                        a->c = black;
                        b->c = red;
                        b->r->c = black;
                    }
                    else if(b->l->c == red){
                        rightrotate(b);
                        leftrotate(a);
                        a->c = black;
                    }
                    //case 1.2
                    else{
                        a->c = black;
                        b->c = red;
                    }
                }
                else{
                    if(b->c == red){
                        Node *cc = b->l;
                        // case 2.1.1
                        if(cc->l->c == red || cc->r->c == red){
                            // here a is black b is red and its left child c has a left child as red and right child as black
                            // hence we rotate at c and exchange color so that new c has its right child as red
                            if(cc->l->c == red && cc->r->c == black){
                                rightrotate(cc);
                                cc = b->l;
                                cc->c = black;
                                cc->r->c = red;
                            }
                            Node *d = cc->r;
                            rightrotate(b);
                            leftrotate(a);
                            if(d->c == red) d->c = black;
                        }
                        // case 2.1.2
                        else{
                            leftrotate(a);
                            b->c = black;
                            cc->c = red;
                        }
                    } 
                    else{
                        //case 2.2.1
                        if(b->r->c == red){
                        // RR case
                            leftrotate(a);
                            b->r->c = black;
                        }
                        else if(b->l->c == red){
                            //RL case
                            Node *cc = b->l;
                            rightrotate(b);
                            leftrotate(a);
                            cc->c = black;
                        }
                        else{
                            //case 2.2.2
                            b->c = red;
                            fixupdelete(a);
                        }
                    }
                }
            
            }
            
            root->c = black;
        }

        std::tuple<bool, int, int> checkTree(Node *node, int h, int bh){
            if(node == nil) return std::make_tuple(h == bh, -1, -1);                                                                    ;
            if(node->c == red && (node->l->c == red || node->r->c == red)) return std::make_tuple(false, -1, -1);
            if(node->c == black) ++h;

            auto left = checkTree(node->l, h, bh);
            auto right = checkTree(node->r, h, bh);

            if(std::get<0>(left) == false || std::get<0>(right) == false) return std::make_tuple(false, -1, -1);

            // this condition is important and was missed before
            // not just min both min and max of left side should be less than node key and both
            // min and max of right side should be less than node key for the bst property
            // this was not giving error because I was making tree with right bst property
            if((node->l != nil && (std::get<1>(left) >= node->key || std::get<2>(left) >= node->key)) ||
                        (node->r != nil && (std::get<1>(right) <= node->key || std::get<2>(right) <= node->key))) 
                    return std::make_tuple(false, -1, -1);

            int tmin = node->l != nil? std::get<1>(left) : node->key;
            int tmax = node->r != nil? std::get<2>(right) : node->key;


            return std::make_tuple(true, tmin, tmax);
            
        }

        int getblackheight(){
            Node *t = root;
            int bh = 0;
            while(t != nil){
                if(t->c == black) ++bh;
                t = t->l;
            }

            return bh;
        }

        void check(){
            int bh = getblackheight();
            // std::cout<<"black height: "<<bh<<std::endl;
            auto res = checkTree(root, 0, bh);
            if(std::get<0>(res)){} //std::cout<<"Valid Tree\n";
            else {
                std::cout<<"Invalid Tree\n";
                print();
                exit(1);
            }

        }

};

int main(){
    RBtree r;

    // r.check();
    // r.insert(2);
    // r.check();
    // r.insert(3);
    // r.check();
    // r.insert(4);
    // r.check();
    // r.insert(5);
    // r.check();
    // r.insert(6);
    // r.check();
    // r.insert(7);
    // r.check();
    // r.insert(8);
    // r.check();
    // r.insert(9);
    // r.check();
    // r.insert(10);
    // r.check();
    // r.insert(11);
    // r.check();
    // r.insert(12);
    // r.check();
    // r.insert(13);
    // r.check();
    // r.insert(14);
    // r.check();
    // r.insert(15);
    // r.check();
    // r.print();
    // // std::cout<<"after deletion:\n";
    // r.remove(r.root, 5);
    // r.check();
    // r.remove(r.root, 4);
    // r.check();
    // r.remove(r.root, 3);
    // r.check();
    // r.remove(r.root, 2);
    // r.check();
    // r.remove(r.root, 1);
    // r.check();
    // r.remove(r.root, 10);
    // r.check();
    // r.remove(r.root, 9);
    // r.check();
    // r.remove(r.root, 8);
    // r.check();
    // r.remove(r.root, 7);
    // r.check();
    // // r.print();
    // r.remove(r.root, 6);
    // r.check();
    // // r.print();
    // r.remove(r.root, 15);
    // r.check();
    // r.remove(r.root, 14);
    // r.check();
    // r.remove(r.root, 13);
    // r.check();
    // r.remove(r.root, 12);
    // r.check();
    // r.remove(r.root, 11);
    // r.check();
    // r.remove(r.root, 6);
    // r.check();


    int limit = 100;
    std::vector<int> vals(limit);
    for(int i = 0; i < limit; ++i) vals[i] = i;

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    shuffle(vals.begin(), vals.end(), std::default_random_engine(seed));

    // std::vector<int> vals1 = {0,8,5,7,9,2,6,4,1,3};
    // std::vector<int> vals2 = {0,1,2,4,3};


    // std::cout<<"values inserted\n";
    for (int& x: vals){
        // std::cout<<x<<" ";
        r.insert(x);
        r.check();
    }
    // std::cout<<"\n";

    // r.print();
    shuffle(vals.begin(), vals.end(), std::default_random_engine(seed));
    // std::cout<<"\nvalues removed\n";
    for (int& x: vals){
        // std::cout<<x<<" ";
        r.remove(r.root, x);
        // r.print();
        r.check();
    }

    //    r.print();
    
}
