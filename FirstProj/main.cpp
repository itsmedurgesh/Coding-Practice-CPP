#include <iostream>
#include <string>

#include <cstdlib>
#include <ctime>

#include "NewTestClass.h"
#include "ConstFuncExmple.h"

#include "Sally.h"
#include "Enemy.h"
#include "FunctionTemplate.h"
#include "TemplateClass.h"

//#include "../../Sources/src/TemplateSpecialization.cpp"


using namespace std;
/*
class TempClass{

    public:
        string name;

        TempClass(string s){
            name = s;
        }
        void sayhello(){
            cout<<name;
        }
        static void sayhello1(){
            cout<<"\nhello guys from static";
        }
};

int volume(int l, int b, int h){ return l*b*h;}
int volume(int l, int b){ return l*b;}
*/

/*
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

*/



int main()
{
    //TempClass t("durgesh");
    //t.sayhello();
    //TempClass::sayhello1();

    //NewTestClass ts;
    /*
    srand(time(0));
    for(int i=0; i<10; i++)
        cout<<rand()%7<<endl;
    */

    //cout<<endl<<volume(4,2);

    //ConstFuncExmple c(3,5);
    //c.printvar();

    //Sally::testOperatorOverloading();
    //testattack();

    //cout<<FunctionTemplate::add(3.2,4.3);
    //cout<<FunctionTemplate::smaller(3.4,4);

    //TemplateClass <double> t(3.4, 4.5);
    //cout<<t.bigger();

    //Spunky <int> s(1);


}
