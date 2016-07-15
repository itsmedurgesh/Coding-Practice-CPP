#ifndef SALLY_H
#define SALLY_H

#include <iostream>

class Sally
{
    public:
        int age;
        Sally();
        virtual ~Sally();
        Sally(int);
        Sally operator+ (Sally);

    static void testOperatorOverloading(){
        Sally s1(21);
        Sally s2(32);

        Sally s3 = s1+s2;

        std::cout<<"new age is: "<<s3.age<<std::endl;

        }
};


#endif // SALLY_H

