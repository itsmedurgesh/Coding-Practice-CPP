
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool issmall(char c){
    return (c >= 'a' && c <= 'z');
}

bool issame(char a, char b){
    return (a == b || (a-32) == b || a == (b-32));
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int q; cin>>q;
    while(q--){
        string a, b;
        cin>>a>>b;

        if(a.size() < b.size()){
            cout<<"NO"<<endl;
            continue;
        }

        int i = 0, j = 0;
        bool flag = true;
        while(j < b.size()){
            if(i == a.size()){ flag = false; break; }
            if(!issame(a[i], b[j]) && !issmall(a[i])){ flag = false; break; }
            if(!issame(a[i], b[j])){ ++i; continue; }

            int smalla = 0, biga = 0, bigb = 1;

            while(j+1 < b.size() && b[j+1] == b[j]){
                ++bigb;
                ++j;
            }

            while(i < a.size() && issame(a[i], b[j])){
                if(issmall(a[i])) ++smalla;
                else ++biga;
                ++i;
            }


            while((smalla + biga) < bigb){
                if(i == a.size()){ flag = false; break; }
                if(!issmall(a[i]) && !issame(a[i], b[j])) { flag = false; break;}
                if(!issame(a[i], b[j])){ ++i; continue; }
                while(i < a.size() && issame(a[i], b[j])){
                    if(issmall(a[i])) ++smalla;
                    else ++biga;
                    ++i;
                }
            }

            if(biga > bigb){ flag = false; break;}


            if(!flag) break;

            ++j;
        }

        while(i < a.size() && flag){
            if(!issmall(a[i])){flag = false; break;}
            ++i;
        }

        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;       

    }
    return 0;
}
