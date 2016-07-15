#include <iostream>
#include <vector>

#define Z 26

using namespace std;
void countingsort_alphabet(vector<string> s, int colidx){
    char* b = new char[size];
    int c[Z];
    
    for(int i=0; i<Z; ++i) 
        c[i] = 0;
   
    for(int i=0; i<size; ++i) 
        ++c[(int)(a[i][colidx])-(int)'a'];
   
    for(int i=1; i<bsize; ++i) 
        c[i] += c[i-1];
   
    for(int i=size-1; i>-1; --i){
        b[c[(int)a[i][colidx]-(int)'a']-1] = a[i][colidx];
        --c[(int)a[i][colidx]-(int)'a'];
    }
    
    for(int i=0; i<size; ++i)
        a[i][colidx] = b[i];
}

void redixsort(vector<string>){
    // TODO:  already implemented in java


}
void print(char** a, int size, int colsize){
    for(int i=0; i<size; ++i){
        cout<<endl;
        for(int j=0; j<colsize; ++j){
            cout<<a[i][j];
        }
    }
        cout<<endl;
}


int main(){

    char** a = new char*[5];
    for(int i=0; i<5; ++i)
        a[i] = new char[3];
    
    a[0] = "axa";
    a[1] = "aba";
    a[2] = "aaa";
    a[3] = "baa";
    a[4] = "ava";

    countingsort_alphabet(a, 1, 26, 5);
    print(a, 5, 3);

}    
