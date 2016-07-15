#include <vector>
#include <iostream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    vector<int> v;
    
    v.push_back(1);
    
    int n;
    
    cin >>n;
    
    long sum = v[0];

    for(int i=1; i<=n; ++i){
        v.push_back(sum%715827881);
        sum = sum + (long)v[i];
        // sum %= 715827881;
        //cout<<sum %715827881<<" ";
        if(i%2 == 0){
            sum -= (long)v[(i-1)/2];
        }

        
    }
    
    sum = 0;
    for(int i=v.size()-2; i>-1; --i){
        sum += (long)v[i];
        sum %= 715827881;
        cout<<sum<<" ";
    }
    
    return 0;
}
