#include <iostream>

using namespace std;

int main(){
    int a[] = {10, 12, 20, 24, 25, 26, 44, 41, 42, 35, 50, 60};
    int size = sizeof(a)/sizeof(int);

    bool found= false;
    int s = -1, e = -1;
    int M = -1;
    for(int i = 0; i < size-1; ++i){
        if(!found && a[i+1] < a[i]){
            found = true;
            int j = i;
            while(j>-1 && a[j]>a[i+1]) --j;
            s = j+1;
            e = i+1;
            M = a[i];
        }
        if(found){
            int j = s;
            while(j > -1 && a[j] > a[i+1]) --j;
            s = min(s, j+1);
            if(a[i+1] < a[i]){ e = i+1; M = max(M, a[i+1]); }
            else if(a[i+1] < M) e = i+1;
        }
    }
    
    cout<<"to sort form "<<s<<" to "<<e<<endl;
}
