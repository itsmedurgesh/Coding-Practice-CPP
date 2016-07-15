#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
// #include <limits>
#include <climits>
using namespace std;

// int INT_MAX = numeric_limits<int>::max();

void findpath(vector<vector<int>> &table, int x, int y, int M, int N){
    //find all posssible moves and fill apt values

    int m;

    //right up
    if(x+2 < N && y+1 < M){
        m = min(table[y+1][x+2], table[y][x]+1);
        if(m != table[y+1][x+2]){
            table[y+1][x+2] = m;
            findpath(table, x+2, y+1, M, N);
        }
    }

    //right down
    if(x+2 < N && y-1 >= 0){
        m = min(table[y-1][x+2], table[y][x]+1);
        if(m != table[y-1][x+2]){
            table[y-1][x+2] = m;
            findpath(table, x+2, y-1, M, N);
        }
    }

    // up right
    if(x+1 < N && y+2 < M){
        m = min(table[y+2][x+1], table[y][x]+1);
        if(m != table[y+2][x+1]){
            table[y+2][x+1] = m;
            findpath(table, x+1, y+2, M, N);
        }
    }

    //up left
    if(x-1 >= 0 && y+2 < M){
        m = min(table[y+2][x-1], table[y][x]+1);
        if(m != table[y+2][x-1]){
            table[y+2][x-1] = m;
            findpath(table, x-1, y+2, M, N);
        }
    }

    // left up
    if(x-2 >= 0 && y+1 < M){
        m = min(table[y+1][x-2], table[y][x]+1);
        if(m != table[y+1][x-2]){
            table[y+1][x-2] = m;
            findpath(table, x-2, y+1, M, N);
        }
    }

    //left down
    if(x-2 >= 0 && y-1 >= 0){
        m = min(table[y-1][x-2], table[y][x]+1);
        if(m != table[y-1][x-2]){
            table[y-1][x-2] = m;
            findpath(table, x-2, y-1, M, N);
        } 
    }

    //bottom left
    if(x-1 >= 0 && y-2 >= 0){
        m = min(table[y-2][x-1], table[y][x]+1);
        if(m != table[y-2][x-1]){
            table[y-2][x-1] = m;
            findpath(table, x-1, y-2, M, N);
        } 
    }

    //bottom right
    if(x+1 < N && y-2 >= 0){
        m = min(table[y-2][x+1], table[y][x]+1);
        if(m != table[y-2][x+1]){
            table[y-2][x+1] = m;
            findpath(table, x+1, y-2, M, N);
        }
    }
}


int knight(int N, int M, int x1, int y1, int x2, int y2) {
    // Do not write main() function.
    //Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<int>> table(M, vector<int> (N, INT_MAX));
    table[y1-1][x1-1] = 0;
    findpath(table, x1-1, y1-1, M, N);
    return table[y2-1][x2-1] == INT_MAX ? -1 : table[y2-1][x2-1];
}

int main(){

    assert(knight(8,8,1,1,8,8) == 6); 
    assert(knight(4,7,2,6,2,4) == 2); 

}
