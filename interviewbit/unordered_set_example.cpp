#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
int main(){
    unordered_set<string> myset;
    myset.insert("fuasdf");
    myset.emplace("jhgfd");
    auto a = myset.insert("dfsdh");
    cout<<a.second<<endl;


    for(const string s: myset){
        // s = "1"+s;
        cout<<s<<endl;
    }
}
