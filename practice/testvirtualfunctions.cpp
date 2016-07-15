#include <iostream>
using namespace std;

class Base{
    public:
        void fun1(){ cout<<"\nthis is fun1 from base"; }
        virtual void fun2() { cout<<"\nthis is fun2 from base"; }
};

class Derived : public Base{
    public:
        void fun1(){ cout<<"\nthis is fun1 from derived"; }
        virtual void fun2() { cout<<"\nthis is fun2 from derived"; }
};

int main(){
    Derived b;
    Base *c = new Derived();
    c->fun1();
    c->fun2();
    delete c;
}
