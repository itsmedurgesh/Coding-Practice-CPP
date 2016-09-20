
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class node{
public:
    int a, t, g, c;
    node(): a(0), t(0), g(0), c(0) {}
    node(int _a, int _t, int _g, int _c): a(_a), t(_t), g(_g), c(_c) {}
};

bool satisfy(int i, int j, vector<node> &vec, node &rnode){
    if(vec[j].a - vec[i-1].a >= rnode.a &&
            vec[j].t - vec[i-1].t >= rnode.t &&
            vec[j].g - vec[i-1].g >= rnode.g &&
            vec[j].c - vec[i-1].c >= rnode.c) return true;
    else return false;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n; cin>>n;
    int ideal = n/4;
    string s; cin>>s;
    vector<node> vec(n+1, node());
    
    int A = 0, T = 0, G = 0, C = 0;
    for(int i = 0; i < n; ++i){
        switch(s[i]){
            case 'A': {
                vec[i+1].a = ++A; 
                vec[i+1].t = T;
                vec[i+1].g = G;
                vec[i+1].c = C;
                break;
            }
            case 'T': {
                vec[i+1].a = A; 
                vec[i+1].t = ++T;
                vec[i+1].g = G;
                vec[i+1].c = C;
                break;
            }
            case 'G': {
                vec[i+1].a = A; 
                vec[i+1].t = T;
                vec[i+1].g = ++G;
                vec[i+1].c = C; 
                break;
            }
            case 'C': {
                vec[i+1].a = A; 
                vec[i+1].t = T;
                vec[i+1].g = G;
                vec[i+1].c = ++C; 
                break;
            }
        }
    }
    
    node rnode(max(0, A - ideal), max(0, T - ideal), max(0, G - ideal), max(0, C - ideal));
    
    int i = 1, j = 1;
    int start = 0, end = n-1;
    
    while(true){
        if(satisfy(i, j, vec, rnode)){
            if(end-start > j-i){
                end = j-1;
                start = i-1;
            }
            ++i;
        }
        else{
            if(j == n) break;
            ++j;
        }
    }

    cout<<s.substr(start, end-start+1)<<endl;
    
    cout<<('B'-'b');
    
    return 0;
}
