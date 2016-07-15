#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
struct node{
    int data;
    int via;
    node *prev;
};
string getmultiple(int A){
    node start;
    start.data = 1;
    start.via = 1;
    start.prev = NULL;

    bool flag=true;
    vector<node *> states;
    states.push_back(&start);
    vector<node *> next;
    node *current = &start;
    
    string ans = "";
    node *end = NULL;
    while(flag){
        for(node *t : states){
            int tt = (t->data*10) %A;
            if(tt == 0){ 
                flag = false; 
                ans += "0";
                end = t;
                break; 
            }

            node *tmp = new node;
            tmp->data = tt;
            tmp->prev = t;
            tmp->via = 0;
            next.push_back(tmp);

            tt = (t->data*10 + 1) %A;
            if(tt == 0){ 
                flag = false; 
                ans += "1";
                end = t;
                break; 
            }
            tmp = new node;
            tmp->data = tt;
            tmp->prev = t;
            tmp->via = 1;
            next.push_back(tmp);
        }

        states.swap(next);
        next.clear();

        if(!flag){
            while(end){
                ans += to_string(end->via);
                end = end->prev;
            }
        }
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    cout<<getmultiple(55)<<endl;
}
