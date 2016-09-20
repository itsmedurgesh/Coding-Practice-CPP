
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    vector<int> l;
    int d;
    for(int i = 0; i < n; ++i){
        cin>>d;
        l.push_back(d);
    }
    
    sort(l.begin(), l.end(), greater<int>());
    
    bool found = false;
    
    int a = l[0], b = l[1], c = l[2];
    for(int i = 3; i < n; ++i){
        if(a < b+c && b < a+c && c < a+b){found = true; break;}
        if(a >= b+c) a = l[i];
        else if(b >= a+c) b = l[i];
        else if(c >= a+b) c = l[i];
    }
    
    if(found){
        if(a > b) swap(a, b);
        if(b > c) swap(b, c);
        if(a > b) swap(a, b);
        cout<<a<<" "<<b<<" "<<c<<" "<<endl;
    }
    else cout<<-1<<endl;
        
    return 0;
}
