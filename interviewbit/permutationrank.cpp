#include <iostream>
#include <vector>

using namespace std;

#define MAX 26

long fact(long x){ return x <= 1 ? 1 : x*fact(x-1); }

void populate(vector<int> &count, string s){
    for(char c: s){
        // cout<<(int)(c-'A')<<endl;
        ++count[(int)(c-'A')];
    } 
    for(int i = 1; i < MAX; ++i) count[i] += count[i-1];
}

void updatecount(vector<int> &count, char c){
    for(int i = (int)(c-'A'); i < MAX; ++i) --count[i];
}

int findRank(string A) {
    int len = A.size();
    long f = fact(len);
    long rank = 1;
    vector<int> count(MAX, 0);

    populate(count, A);

    for(int i = 0; i < len; ++i){
        f /= len-i;
        rank += f*(long)count[(int)(A[i]-'A')];
        rank %= 1000003;
        updatecount(count, A[i]);
    }

    return rank;
}
int main(){
    // cout<<findRank("ACB")<<endl;
    int a = 0b10;
    a *= 0b11;
    cout<<a;
}
