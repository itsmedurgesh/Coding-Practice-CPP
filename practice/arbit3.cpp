#include <iostream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    
    for(int p=0; p<t; ++p){
        int n;
        cin>>n;
        
        long sum = 0;
        long a = n/3;
        if(3*a == n) --a;
        long b = n/5;
        if(5*b == n) --b;
        long c = n/15;
        if(15*c == n) --c;
       
       sum += 3*a*(a+1)/2;
       sum += 5*b*(b+1)/2;
       sum -= 15*c*(c+1)/2;
       
        cout<<sum<<endl;
    }
    
    return 0;
}

