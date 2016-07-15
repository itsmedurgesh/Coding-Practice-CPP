#include <iostream>
    
using namespace std;
int isMatch(const char* s, const char* p) {
    const char* star=NULL;
        const char* ss=s; 
        while (*s){
            if ((*p=='?')||(*p==*s)){s++;p++;continue;}
            if (*p=='*'){star=p++; ss=s;continue;}
            if (star){ p = star+1; s=++ss;continue;}
            return 0;
        }
        while (*p=='*'){p++;}
        return !*p;
}

int main(){
    const char* a = "ab";
    const char* b = "?*";
    cout<<isMatch(a,b);
}
