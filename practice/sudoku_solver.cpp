#include <iostream>
#include <vector>
using namespace std;


bool isvalid(vector<vector<char>> &b, int r, int c, char k) {
    //check row
    for(int i = 0; i<9; ++i){
        if(b[r][i] == k) return false;
    }

    //check column
    for(int i = 0; i<9; ++i){
        if(b[i][c] == k) return false;
    }

    //check block
    int blockx = r/3;
    int blocky = c/3;
    for(int i = 3*blockx; i< 3*blockx+3; ++i){
        for(int j = 3*blocky; j<3*blocky+3; ++j){
            if(b[i][j] == k) return false;
        }
    }

    return true;
}

bool solver(vector<vector<char>> &b){
    for(int i = 0; i < 9; ++i){
        for(int j = 0; j<9; ++j){
            if(b[i][j] == '.'){
                for(int k = 1; k < 10; ++k){
                   if(isvalid(b, i, j, (char)('0'+k))){
                        b[i][j] = (char)('0' + k);
                            
                        if(solver(b)) return true;
                        b[i][j] = '.';
                   }
                }
                return false;
            }
        }
    }

    return true;
}

void print(vector<vector<char>> &b){
    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9 ; ++j) cout<<b[i][j]<<" ";
        cout<<endl;
    }
}

int main(){
    vector<vector<char>> board = {{'.', '2', '6', '5', '.', '.', '.', '9', '.'},
                          {'5', '.', '.', '.', '7', '9', '.', '.', '4'},
                          {'3', '.', '.', '.', '1', '.', '.', '.', '.'},
                          {'6', '.', '.', '.', '.', '.', '8', '.', '7'},
                          {'.', '7', '5', '.', '2', '.', '.', '1', '.'},
                          {'.', '1', '.', '.', '.', '.', '4', '.', '.'},
                          {'.', '.', '.', '3', '.', '8', '9', '.', '2'},
                          {'7', '.', '.', '.', '6', '.', '.', '4', '.'},
                          {'.', '3', '.', '2', '.', '.', '1', '.', '.'}};
    solver(board);
    print(board);
    
}
