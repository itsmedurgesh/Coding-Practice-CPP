#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <climits>
#include <set>
using namespace std;

#define mk make_pair
#define pb push_back

int knight(int N, int M, int x1, int y1, int x2, int y2) {
    // Do not write main() function.
    //Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(x1 == x2 && y1 == y2) return 0;

    vector<pair<int, int>> current, next;
    
    set<pair<int,int>> v;

    current.pb(mk(x1, y1));
    v.insert(mk(x1,y1));

    int step = 0;
    while(current.size()){
        for(auto p : current){
            
            int x = p.first;
            int y = p.second;
            if(x == x2 && y == y2) return step;

            //right up
            if(x+2 <= N && y+1 <= M && !v.count(mk(x+2, y+1))){
                next.pb(mk(x+2, y+1));
                v.insert(mk(x+2, y+1));
            }

            //right down
            if(x+2 <= N && y-1 >= 1 && !v.count(mk(x+2, y-1))){
                next.pb(mk(x+2, y-1));
                v.insert(mk(x+2, y-1));
            }

            // up right
            if(x+1 <= N && y+2 <= M && !v.count(mk(x+1, y+2))){
                next.pb(mk(x+1, y+2));
                v.insert(mk(x+1, y+2));
            }

            // up left
            if(x-1 >= 1 && y+2 <= M && !v.count(mk(x-1, y+2))){
                next.pb(mk(x-1, y+2));
                v.insert(mk(x-1, y+2));
            }

            // left up
            if(x-2 >= 1 && y+1 <= M && !v.count(mk(x-2, y+1))){
                next.pb(mk(x-2, y+1));
                v.insert(mk(x-2, y+1));
            }

            // left down
            if(x-2 >= 1 && y-1 >= 1 && !v.count(mk(x-2, y-1))){
                next.pb(mk(x-2, y-1));
                v.insert(mk(x-2, y-1));
            }

            //bottom left
            if(x-1 >= 1 && y-2 >= 1 && !v.count(mk(x-1, y-2))){
                next.pb(mk(x-1, y-2));
                v.insert(mk(x-1, y-2));
            }

            //bottom right
            if(x+1 <= N && y-2 >= 1 && !v.count(mk(x+1, y-2))){
                next.pb(mk(x+1, y-2));
                v.insert(mk(x+1, y-2));
            }
        }

        ++step;
        current.clear();
        current.swap(next);
    }
     return -1;
}

int main(){

    assert(knight(8,8,1,1,8,8) == 6); 
    assert(knight(4,7,2,6,2,4) == 2); 

}
