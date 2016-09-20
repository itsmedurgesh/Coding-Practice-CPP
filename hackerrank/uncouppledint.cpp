#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int res = 0;
    int d;
    string line;
    while(cin>>d){
        res ^= d;
        if(cin.peek() == ',') cin.ignore();
    } 
    cout<<res<<endl;
    return 0;
}
