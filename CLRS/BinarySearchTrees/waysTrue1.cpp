#include <iostream>

using namespace std;

int ways(string A, bool val){
    if(A.size() == 0) return 0;
    if(A == "T") return val == true;
    if(A == "F") return val == false;

    int ans = 0;
    for(int i = 1; i < A.size(); ++i){
        if(A[i] == '|'){
            if(val){
                ans += ways(A.substr(0, i), true)*ways(A.substr(i+1), true)
                    + ways(A.substr(0, i), false)*ways(A.substr(i+1), true)
                    + ways(A.substr(0, i), true)*ways(A.substr(i+1), false);
                ans %= 1003;
            }
            else{
                ans += ways(A.substr(0, i), false)*ways(A.substr(i+1), false);
                ans %= 1003;
            }
        }
        else if(A[i] == '&'){
            if(val){
                ans += ways(A.substr(0, i), true)*ways(A.substr(i+1), true);
                ans %= 1003;
            }
            else{
                ans += ways(A.substr(0, i), false)*ways(A.substr(i+1), false)
                    + ways(A.substr(0, i), false)*ways(A.substr(i+1), true)
                    + ways(A.substr(0, i), true)*ways(A.substr(i+1), false);
                ans %= 1003;
            }
        }
        else if(A[i] == '^'){
            if(val){
                ans += ways(A.substr(0, i), true)*ways(A.substr(i+1), false)
                    + ways(A.substr(0, i), false)*ways(A.substr(i+1), true);
                ans %= 1003;
            }
            else{
                ans += ways(A.substr(0, i), true)*ways(A.substr(i+1), true);
                ans += ways(A.substr(0, i), false)*ways(A.substr(i+1), false);
                ans %= 1003;
            }

        }
    }

    return ans;
}


int main(){

    cout<<ways("F|T^T&F", true)<<endl;

}
