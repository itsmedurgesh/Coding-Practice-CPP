#include <iostream>
using namespace std;

template<class T>
class Spunky{
    public:
        Spunky(T x){
            cout<<"this does not seem like a character\n";
        }
};

template<>
class Spunky<char>{
    public:
        Spunky(char x){
            cout<<"this seems like a character\n";
        }
};
