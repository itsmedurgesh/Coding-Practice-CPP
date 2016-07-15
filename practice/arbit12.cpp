#include <iostream>
#include <vector>

using namespace std;

void p(vector<int> a){
    cout<<"1st call\n";
    for(int i : a) cout<<i<<" ";
    cout<<endl;
}
void p(vector<int> &a){
    cout<<"2nd call\n";
    for(int i : a) cout<<i<<" ";
    cout<<endl;
}
void p(vector<int> && a){
    cout<<"3rd call\n";
    for(int i : a) cout<<i<<" ";
    cout<<endl;
}

int main(){

    p(new vector<int>(){1,2,3});
}
