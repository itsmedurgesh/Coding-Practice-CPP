#include <iostream>
#include <limits>
using namespace std;

int reverse(int A) {
    
    int sign = A < 0 ? -1 : 1;
    long a = (long)A;
    long b = 0;
    
    while(a){
        b = b*10 + a%10;
        a /= 10;
    }
    
    //b *= sign;
    
    if(b > numeric_limits<int>::max() || b < numeric_limits<int>::min()) return 0;
    return (int)b;
}
string convertToTitle(int A) {
    
    bool flag = false;
    string res = "";
    while(A){
        int t = A%26;
        --t;
        if(flag){ --t; flag = false; }
        if(t == -1){ t = 25; flag = true;}
        res = (char)('A' + t) + res;
        A /= 26;
    }
    
    return res;
    
}

string findDigitsInBinary(int A) {
    string ans = "";
    while(A){
        ans += (char)(A%2);
        A /= 2;
    }
    // reverse(begin(ans), end(ans));
    return ans;
}
int main(){
    // cout<<reverse(-1000000003 );
    // cout<< numeric_limits<int>::max();

    // int a = 1024000000;
    // while(a){
    //     cout<<a%2<<" ";
    //     a /= 2;
    // }
    // char c = 'a' + 1;
    // cout<<c;

    // cout<<convertToTitle(468096);

    cout<<findDigitsInBinary(1);

}
