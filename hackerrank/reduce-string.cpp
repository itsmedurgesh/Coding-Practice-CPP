
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string s;
    cin>>s;
    
    bool toshort = true;
    
    while(toshort && s.size()){
        toshort = false;
        for(int i = 0; i < s.size()-1; ++i){
            if(s[i] == s[i+1]){
                toshort = true;
                s.erase(i, 2);
                break;
            }
        }
    }
    
    if(s.size()) cout<<s<<endl;
    else cout<<"Empty String"<<endl;
    return 0;
}
