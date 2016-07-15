#include "NewTestClass.h"
#include <iostream>

using namespace std;

NewTestClass::NewTestClass()
{
    //ctor
    cout<<"\nthis is constructor called";
}

NewTestClass::~NewTestClass()
{
    //dtor
    cout<<"\nthis is distructor called";
}
