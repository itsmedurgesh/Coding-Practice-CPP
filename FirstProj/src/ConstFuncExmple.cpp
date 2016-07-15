#include "ConstFuncExmple.h"
#include <iostream>
using namespace std;

ConstFuncExmple::ConstFuncExmple(int a, int b) : var(a), constvar(b)
{
    //ctor
}

ConstFuncExmple::~ConstFuncExmple()
{
    //dtor
}

void ConstFuncExmple::regfunc(){
    cout<<"this is a regular function";
}

void ConstFuncExmple::constfunc() const{
    cout<<"this is a constant function";
}

void ConstFuncExmple::printvar(){
    cout<<"var: "<<var<<endl<<"constvar: "<<constvar;
}
