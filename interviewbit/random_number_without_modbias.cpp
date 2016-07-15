#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    int x;
    int n = 10;
    srand(time(0));
    do{
        x = rand();
    }while(x >= (RAND_MAX - RAND_MAX % n));
    cout<<x%n;
}
