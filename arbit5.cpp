#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int a[] = {15,2,65,1,2,8,7,23};
    sort(begin(a), end(a));
    for(auto it = begin(a); it != end(a); ++it) cout<< *it<<" ";

}
