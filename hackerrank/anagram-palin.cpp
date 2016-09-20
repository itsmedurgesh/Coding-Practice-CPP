
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string s; cin>>s;
    int a[26]= {0};
    for(char c: s) a[c-'a'] ^= 1;
    int odds = 0;
    for (int i : a) if(i) ++odds;
    if(s.size()&1 && odds == 1) cout<<"YES";
    else if(s.size()&1 == 0 && odds == 0) cout<<"YES";
    else cout<<"NO";
    return 0;
}
