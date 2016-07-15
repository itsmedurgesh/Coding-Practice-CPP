#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int a[] = {1, 2, 4, 9, 6, 5, 9, 8, 10, 3};

    for(int i = 0; i < 10; ++i) 
        if(a[abs(a[i])-1] > 0) 
            a[abs(a[i])-1] = -a[abs(a[i])-1];
        else cout<<"repeating number is "<<abs(a[i]);
    for(int i = 0; i < 10; ++i)
        if(a[i] > 0) cout<<"\nmissing number is "<<i+1;

}
