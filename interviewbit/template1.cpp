#include <iostream>
template <int N>
struct Factorial 
{
    enum { value = N * Factorial<N - 1>::value };
};

template <>
struct Factorial<0> 
{
    enum { value = 1 };
};

// Factorial<4>::value == 24
// Factorial<0>::value == 1
void foo()
{
    int x = Factorial<4>::value; // == 24
    std::cout<<x<<std::endl;
    int y = Factorial<0>::value; // == 1
    std::cout<<y<<std::endl;
}

int main(){
    foo();
}