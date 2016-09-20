
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define a 100001
#define m 1000000001

template <typename T>
T modpow(T base, T exp, T modulus) {
  base %= modulus;
  T result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}

int f(string &p){
    int n = p.size();
    int res = 0;
    for(int i = 0; i < n; ++i){
        res += (int)(((long)p[i] * (long)modpow<int>(a, n-1-i, m)) % (long)m);
        res %= m;
    }

    return res;
}

bool ispalin(string &s){
    for(int i = 0; i < s.size()/2; ++i){
        if(s[i] != s[s.size()-1-i]) return false;
    }
    return true;
}

void generate(string s, vector<string> & palins){
    int tsize = s.size();
    for(int len=1; len <= tsize; ++len){
        for(int i = 0; i + len <= tsize; ++i){
            string t = s.substr(i, len);
            if(ispalin(t)) palins.push_back(t);
        }
    }

    sort(palins.begin(), palins.end());
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, q; cin>>n>>q;
    string s; cin>>s;
    vector<string> palins;
    generate(s, palins);
    int k;
    for(int i = 0; i < q; ++i){
        cin>>k;
        if(k > palins.size()) cout<<-1<<"\n";
        else cout<<f(palins[k-1])<<"\n";
    }
    return 0;
}
