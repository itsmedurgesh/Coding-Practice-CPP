#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
#include <string>
using namespace std;

string add(string &a, string &b){
    string c;
    c.reserve(max(a.size(), b.size())+1);
    int carry = 0;
    int x, y, sum;
    for(int i = a.size()-1, j = b.size()-1; i >= 0 || j >= 0; --i, --j){
        x = i >= 0 ? (a[i] - '0') : 0;
        y = j >= 0 ? (b[j] - '0') : 0;
        sum = x+y+carry;
        carry = sum/10;
        sum %= 10;
        c.append(to_string(sum));
    }
    if(carry) c.append(to_string(carry));
    
    reverse(c.begin(), c.end());
    return c;    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    vector<int> ins;
    int d;
    int largest = numeric_limits<int>::min();
    while(cin>>d){
        ins.push_back(d);
        if(d > largest) largest = d;
    }
    
    vector<string> fibs;
    fibs.reserve(largest);
    fibs.push_back("0");
    fibs.push_back("1");
    
    --largest;
    string first = "0", second = "1", third;
    while(largest--){
        third = add(first, second);
        fibs.push_back(third);
        first = second;
        second = third;
    }
    
    for(int i : ins){
        cout<<fibs[i]<<endl;
    }
    
    return 0;
}
