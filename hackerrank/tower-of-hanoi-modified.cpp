/* the algorithm is not clear in the editorial section and
 * this solution times out
 * /
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1000

int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    for(int a_i = 0;a_i < N;a_i++){
       cin >> a[a_i];
    }
    stack<int> s[4];
    for(int i = N-1; i >= 0; --i){
        s[a[i]-1].push(i);
    }
    int ans = 0;
    while(!s[1].empty() || !s[2].empty() || !s[3].empty()){
        int tmax = s[1].empty() ? -1 : 1;
        if(!s[2].empty()){
            if(tmax == -1) tmax = 2;
            else if(s[2].top() > s[tmax].top()) tmax = 2;
        }
        if(!s[3].empty()){
            if(tmax == -1) tmax = 3;
            else if(s[3].top() > s[tmax].top()) tmax = 3;
        }        
        
        ++ans;
        
        if(s[0].empty() || s[tmax].top() < s[0].top()){
            s[0].push(s[tmax].top());
            s[tmax].pop();
            continue;
        }
        
        int tmin = s[1].empty() ? -1 : 1;
        if(!s[2].empty()){
            if(tmin == -1) tmax = 1;
            else if(s[2].top() < s[tmin].top()) tmin = 2;
        }
        if(!s[3].empty()){
            if(tmin == -1) tmin = 3;
            else if(s[3].top() < s[tmin].top()) tmin = 3;
        }
        int order[3] = {0};
        if(tmax == tmin){
            if(tmax == 3) order[0] = 1;
            else order[0] = tmax + 1;
        }
        else{
            order[0] = tmin;
            order[2] = tmax;
            for(int i = 1; i < 4; ++i) if(i != tmax && i != tmin){
                order[1] = i;
                break;
            }
        }
        
        if(s[order[0]].empty() || s[0].top() < s[order[0]].top()){
            s[order[0]].push(s[0].top());
            s[0].pop();
            continue;
        }
        if(s[order[1]].empty() || s[0].top() < s[order[1]].top()){
            s[order[1]].push(s[0].top());
            s[0].pop();
            continue;
        }
        s[order[2]].push(s[0].top());
        s[0].pop();       
        
    }
    
    cout<<ans<<endl;
    
    return 0;
}
