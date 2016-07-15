#include "Sally.h"

Sally::Sally()
{
    //ctor
}

Sally::Sally(int n) : age(n){}

Sally::~Sally()
{
    //dtor
}

Sally Sally::operator+(Sally s){
    Sally newsally;
    newsally.age = age + s.age;

    return newsally;
}
