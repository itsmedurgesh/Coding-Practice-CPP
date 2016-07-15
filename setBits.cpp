#include <iostream>
#include <bitset>

int NumberOfSetBits(uint32_t i)
{
     // Java: use >>> instead of >>
     // C or C++: use uint32_t
     i = i - ((i >> 1) & 0x55555555);
     i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
     return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

int main(){
    std::cout<<NumberOfSetBits(28)<<std::endl;
    std::cout<<__builtin_popcount (28)<<std::endl;
    std::bitset<32> a = 28;
    std::cout<<a.count()<<std::endl;

}
