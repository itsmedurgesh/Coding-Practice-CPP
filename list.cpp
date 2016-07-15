#include <iostream>
#include <list>
using namespace std;
int main(){
    list<int> l;
    for(int i = 0; i <10; ++i)  l.push_back(i);

    int *p = new int[10];
    

    for(int i = 11; i <20; ++i)  l.push_back(i);

    for(auto it = l.begin(); it!= l.end(); ++it) cout<<*it<<" ";

}
