#include <iostream>
#include <climits>
#include <unordered_map>
using namespace std;

string frac2dec(int num, int denom){
    int sign = (num < 0 && denom >= 0)||(num>=0 && denom < 0) ? 1 : 0;
    long n = abs((long)num);
    long m = abs((long)denom);   
    
    string res = sign && n !=0  ? "-" : "";

    res += to_string(n/m);
    long rem = n%m;
    
    unordered_map<long, int> h;
    string sec = ".";
    int i = 1;
    while(rem){
        if(h.find(rem) != h.end()){
            int pos = h[rem];
           sec.insert(pos, "(");
           return res + sec + ")";
        }
        h[rem] = i;
        rem *= 10;
        sec += to_string(rem/m);
        rem %= m;
        ++i;
    }

    if(sec.length() == 1) return res;
    else return res + sec;
}

int main(){
    cout<<frac2dec(1, 1);   }
