#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
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

string multiply(string &a, string &b){
    string c;
    //c.reserve() something
    string d;
    d.reserve(a.size()+1);
    
    for(int i = b.size()-1; i >= 0; --i){   // for string b
        int carry = 0;
        
        for(int k = 1; k < b.size()-i; ++k) d.append("0");
        
        for(int j = a.size()-1; j >= 0; --j){   // for string a
            int x = a[j] - '0';
            int y = b[i] - '0';
            int m = x*y + carry;
            carry = m/10;
            m %= 10;
            d.append(to_string(m));
        }
        if(carry) d.append(to_string(carry));
        reverse(d.begin(), d.end());
        c = add(c, d);
        d.clear();
    }
    
    return c;
}

int main(){
    string a = "11";
    string b = "11";
    cout<<multiply(a, b);
}
